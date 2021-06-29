#include <iostream>

using namespace std;

void print_array(int* A, int n){
   for(int i = 0; i < n; i++){
      cout << A[i];
      if(i != n - 1){
         cout << " ";
      }
   }
   cout << endl;
}

void InsertionSort(int* A, int n){
   for(int i = 1; i < n; i++){
      int v = A[i];
      
      int j = i - 1;

      while(j >= 0 && A[j] > v){
         A[j + 1] = A[j];
         j--;
      }

      A[j + 1] = v;

      print_array(A, n);

   }
}

int main(){

   int n;
   int A[100];

   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> A[i];
   }

   print_array(A, n);

   InsertionSort(A, n);

   return 0;
}
