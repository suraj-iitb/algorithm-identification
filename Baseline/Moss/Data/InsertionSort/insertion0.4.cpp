// C++ program for insertion sort 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
	int i=1, key, j; 
	while ( i < n ) 
	{ 
		key = arr[i]; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		for (j = i - 1; j >= 0 && arr[j] > key; j--) 
		{ 
			arr[j + 1] = arr[j]; 
		} 
		arr[j + 1] = key; 
        i++;
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/* Driver code */
int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	insertionSort(arr, n); 
	printArray(arr, n); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
