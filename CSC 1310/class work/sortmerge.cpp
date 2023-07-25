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
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
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
	merge(myArr, n);

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

void mergeSort(int *arr, int first, int last){
	int middle;
	if(first < last) {
		middle = (first + last)/2;
		mergeSort(arr, first, middle);
		mergeSort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
}
void merge(int *arr, int first, int middle, int last) {
	cout << "Entered merge" << endl;
	int size1 = middle - first + 1;
	int size2 = last - middle;
	int arr1[size1];
	int arr2[size2];
	for(int i = 1; i < size1; i++){
		
	}
}
/*
void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

 void merge(int a[],int p,int q,int r)
{
	cout<<"Entered merge"<<endl;
	int n1=q-p+1;
	int n2=r-q;
	int arr1[n1+1];
	int arr2[n2+1];
	for(int i=1;i<=n1;i++)
	{
		arr1[i]=a[p+i-1];
	}
	for(int j=1;j<=n2;j++)
	{
		arr2[j]=a[q+j];
	}
	arr1[n1+1]=999;
	arr2[n2+1]=999;
	int i=1, j=1;
	for(int k=p;k<=r;k++)
	{
		if(arr[i]<=R[j])
		{
			a[k]=L[i];
			i=i+1;
		}
		else
		{
			a[k]=R[j];
			j=j+1;
		}
	}
}
