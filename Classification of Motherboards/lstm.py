import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Reshape, Dense, Flatten, Dropout
import os
import numpy as np
from tensorflow.keras.preprocessing import image
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix

def load_images_from_folder(folder, label):
    images = []
    labels = []
    for filename in os.listdir(folder):
        if filename.endswith(".png"):
            img = image.load_img(os.path.join(folder, filename), target_size=(224, 224))
            img = image.img_to_array(img)
            img = np.expand_dims(img, axis=0)
            img /= 255.0
            images.append(img)
            labels.append(label)
    if not images:
        print(f"No images found in {folder}")
        return np.array([]), labels
    return np.vstack(images), labels

# Paths to the datasets
path_motherboard = '/home/kasej/Downloads/archive/train/64x64/set-2/2/'  # Update with your actual path
path_non_motherboard = '/home/kasej/Downloads/archive/test/64x64/1/'  # Update with your actual path

# Load motherboard images
images_motherboard, labels_motherboard = load_images_from_folder(path_motherboard, 1)  # label 1 for motherboards

# Load non-motherboard images
images_non_motherboard, labels_non_motherboard = load_images_from_folder(path_non_motherboard, 0)  # label 0 for non-motherboards

# Combine both datasets
images = np.concatenate((images_motherboard, images_non_motherboard), axis=0)
labels = np.concatenate((labels_motherboard, labels_non_motherboard), axis=0)

# LSTM Model with Dropout
lstm_model = Sequential()
lstm_model.add(Reshape((224, 224*3), input_shape=(224, 224, 3)))  # Reshaping for LSTM
lstm_model.add(LSTM(32, return_sequences=True))  # Reduced LSTM units
lstm_model.add(Flatten())
lstm_model.add(Dense(64, activation='relu'))
lstm_model.add(Dense(1, activation='sigmoid'))

# Compile the LSTM model
lstm_model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Split the data
X_train, X_test, y_train, y_test = train_test_split(images, labels, test_size=0.2, random_state=42)

# Continue with model training
lstm_model.fit(X_train, y_train, epochs=10, batch_size=32, validation_split=0.1)

# Evaluate the LSTM model
y_pred_lstm = lstm_model.predict(X_test)
y_pred_lstm = [1 if y > 0.5 else 0 for y in y_pred_lstm]

print("LSTM Model Evaluation:")
print("Confusion Matrix:", confusion_matrix(y_test, y_pred_lstm))
print("Accuracy:", accuracy_score(y_test, y_pred_lstm))
print("Precision:", precision_score(y_test, y_pred_lstm))
print("Recall:", recall_score(y_test, y_pred_lstm))
print("F1 Score:", f1_score(y_test, y_pred_lstm))

# Save the LSTM model
lstm_model.save('lstm_model.h5')

