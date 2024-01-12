import os
import numpy as np
from tensorflow.keras.preprocessing import image
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix

#Directory where your images are stored
data_dir_motherboard = '/Users/abdel/Desktop/5240 AI/Project/True_images/'
data_dir_non_motherboard = '/Users/abdel/Desktop/5240 AI/Project/False_images/'

def load_images_from_folder(folder, label):
    images = []
    labels = []
    for filename in os.listdir(folder):
        if filename.endswith(".jpg"): 
            img = image.load_img(os.path.join(folder, filename), target_size=(224, 224))
            img = image.img_to_array(img)
            img = np.expand_dims(img, axis=0)
            img /= 255.0
            images.append(img)
            labels.append(label)
    return np.vstack(images), labels
#Load images and labels
images_motherboard, labels_motherboard = load_images_from_folder(data_dir_motherboard, 1)
images_non_motherboard, labels_non_motherboard = load_images_from_folder(data_dir_non_motherboard, 0)
#Combine and split data
X = np.concatenate((images_motherboard, images_non_motherboard), axis=0)
y = np.array(labels_motherboard + labels_non_motherboard)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
#Define a simple CNN model
model = Sequential()
model.add(Conv2D(32, (3, 3), activation='relu', input_shape=(224, 224, 3)))
model.add(MaxPooling2D((2, 2)))
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(MaxPooling2D((2, 2)))
model.add(Flatten())
model.add(Dense(64, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

#Compile the model
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

#Train the model
model.fit(X_train, y_train, epochs=10, batch_size=32, validation_split=0.1)

#Evaluate the model
y_pred = model.predict(X_test)
y_pred = [1 if y > 0.5 else 0 for y in y_pred]

print("Confusion Matrix:", confusion_matrix(y_test, y_pred))
print("Accuracy:", accuracy_score(y_test, y_pred))
print("Precision:", precision_score(y_test, y_pred))
print("Recall:", recall_score(y_test, y_pred))
print("F1 Score:", f1_score(y_test, y_pred))

model.save('my_model.h5')