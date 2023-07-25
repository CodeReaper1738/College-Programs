/*
	Purpose:	In-class Practice for sorting
*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void displayArray(int*, int);
void changeToChar(int*,int);
void bubbleSort(int*, int);
void swapping(int &, int &);
void display(int *, int );

int main()
{	

	string plainText;
	int i;
    cout << "\n\nEnter a string of characters: ";
    getline(cin, plainText);
	
	int n=plainText.size();
	int myArr[n];
	
    for ( i = 0; i < n; i++) 
	{
		myArr[i] = static_cast<int>(plainText[i]);
    }
    cout << "\n\n#################################################";
	//display the array
	cout << "\n\nArray before changing to ASCII values: " << plainText << endl;
    cout << "ASCII Array before Sorting: ";
	displayArray(myArr,n);
	
	//sort the array
			/********CALL APPROPRIATE SORT FUNCTION HERE*********/
	bubbleSort(myArr, n);

	//display the array
    cout << "\n\nASCII Array after Sorting: ";
	displayArray(myArr,n);
	changeToChar(myArr,n);
	cout << "\n#################################################";
	cout << endl << endl;

	return 0;
}

void displayArray(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{	
		cout << arr[i]<< " ";
	}
}
void bubbleSort(int *arr, int size)
{
	int x=0;
	cout << "\nSorting the array with the Bubble Sort algorithm.\n\n";
	//maxElement will hold the subscript of the last element 
	//that is to be compared to its immediate neighbor
	for(int maxElement=(size-1); maxElement > 0; maxElement--)
	{
		cout << "\n\nTRAVERSAL NUMBER " << x+1 << "-------------------------------------------------";
		for(int i=0; i<maxElement; i++) //using i for "index"
		{
			cout << "\nComparing " << arr[i] << " & " << arr[i+1];
			//swap the two adjacent elements if the one on the left is greater than the one on the right
			if(arr[i] > arr[i+1]) 
			{
				swapping(arr[i], arr[i+1]);
			}
			else
			{
				cout << "\nNO SWAP";
			}
		}
		displayArray(arr, size);
		x++;
	}
	cout << endl << endl;
}
void changeToChar(int *r,int n) 
{
   int i;
   char s[n];
   cout<<"\n\nThe sorted string is = ";
   for ( i = 0; i < n; i++) 
   {
	   s[i]=static_cast<char>(r[i]);
       cout<<s[i];
   }
   cout<<"\n"; 
}

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
