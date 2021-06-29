#include<iostream>
using namespace std;
void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size-1; i++)
      cout << array[i] << " ";
    cout<<array[size-1];  
    cout << endl;

}
int main() 
{
   int n,swaps=0;
   cin >> n;
   int arr[n];     
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   for(int i = 0; i<n; i++)
   {
       
      for(int j = n-1; j>i; j--) 
      {
         if(arr[j] < arr[j-1]) 
         {       
            swapping(arr[j], arr[j-1]);
            swaps++;    
         }
      }
   }
   display(arr, n);
   cout<<swaps<<endl;
}
