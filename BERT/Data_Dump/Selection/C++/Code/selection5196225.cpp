#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
  
}

// function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size-1; i++)
  {
    cout << array[i] << " ";
  }
  cout<<array[size-1];
  cout << endl;
}

int main()
{
   int n,swaps=0, mini;
   cin >> n;
   int arr[n];     
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
  for (int i = 0; i < n - 1; i++) 
  {
    mini = i;
    for (int j = i ; j < n; j++) 
    {
      if (arr[j] < arr[mini])
      {
        mini = j;
      }
    }
    if(mini!=i)
    {
        swap(&arr[mini], &arr[i]);
        swaps++;
    }
  }
  
  printArray(arr, n);
  cout<<swaps<<endl;
  
  return 0;
}
