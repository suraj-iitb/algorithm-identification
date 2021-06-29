#include<iostream>
#include<algorithm>
using namespace std;

void show(int *array, int size) {
    for(int i = 1; i<=size-1; i++)
        cout << array[i] << " ";
    cout << array[size];
    cout << endl;
}
int find_max(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}

void Sort(int *array, int size) {
   int output[size+1];
   int max = find_max(array, size);
   int count[max+1];     
   for(int i = 0; i<=max; i++)
      count[i] = 0;     
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];    
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; 
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; 
   }
}
int main() {
   int n;
   cin >> n;
   int arr[n+1];       
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }
   Sort(arr, n);
   show(arr, n);
}
