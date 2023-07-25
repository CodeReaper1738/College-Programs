#include<iostream>

using namespace std;

int add(int [], int);

int main() {
	int array[5] = {20, 30, 40, 50, 60};
	int i = 0;
	cout << "\nThe total of the array elements: " << add(array, i) << endl;
	
	return 0;
}

int add(int array[], int i) {
	int num = 0;
	
	
	if(i < 5) {
		//num += array[i];
		//add(array, i++);
		return (array[i--] + add(array[--i], i));
	} else {
		return 0;
	} 
}