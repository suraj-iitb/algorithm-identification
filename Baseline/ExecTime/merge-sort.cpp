/* C program for Merge Sort */
#include <bits/stdc++.h> 

using namespace std;
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int join(int arr[], int left[], int right[], 
          int l, int m, int r) 
{ 
    int i; // Used in second loop 
    for (i = 0; i <= m - l; i++) 
        arr[i] = left[i]; 
  
    for (int j = 0; j < r - m; j++) 
        arr[i + j] = right[j]; 
} 
  
// Function to store alternate elemets in left 
// and right subarray 
int split(int arr[], int left[], int right[], 
          int l, int m, int r) 
{ 
    for (int i = 0; i <= m - l; i++) 
        left[i] = arr[i * 2]; 
  
    for (int i = 0; i < r - m; i++) 
        right[i] = arr[i * 2 + 1]; 
} 
  
// Function to generate Worst Case of Merge Sort 
int generateWorstCase(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
  
        // create two auxillary arrays 
        int left[m - l + 1]; 
        int right[r - m]; 
  
        // Store alternate array elements in left 
        // and right subarray 
        split(arr, left, right, l, m, r); 
  
        // Recurse first and second halves 
        generateWorstCase(left, l, m); 
        generateWorstCase(right, m + 1, r); 
  
        // join left and right subarray 
        join(arr, left, right, l, m, r); 
    } 
} 

/* Driver program to test above functions */
int main() 
{ 
    
    int arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for (int i=0; i<arr_size; i++)
        cin >> arr[i];
  
    generateWorstCase(arr, 0, arr_size - 1); 
    // printf("Given array is \n"); 
    // printArray(arr, arr_size); 

    clock_t start, end; 
    start = clock(); 
    mergeSort(arr, 0, arr_size - 1); 
    end = clock();

    ofstream myfile;
    myfile.open ("time_merge.txt", ios::app);
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    myfile << arr_size << " " << fixed  << time_taken << setprecision(5) << endl;
    myfile.close();
    
    // printf("\nSorted array is \n"); 
    // printArray(arr, arr_size); 
    return 0; 
} 
