#include <iostream>
using namespace std;

void printarr(int arr[], int top) {
   for(int i = 0; i < top - 1; i++) {
      cout << arr[i] << " ";
   }
   cout << arr[top - 1] << endl;
}

int main() {
   int top;
   cin >> top;
   int arr[top], tmp;
   
   for(int i = 0; i < top; i++) {
      cin >> arr[i];
   }
   
   printarr(arr, top);
   
   for(int i = 1; i < top; i++) {
      tmp = arr[i];
      int j = i;
      
      while(j > 0 && tmp < arr[j - 1]) {
         arr[j] = arr[j - 1];
         j--;
      }
         
      arr[j] = tmp;
      printarr(arr, top);
   }
   
   return 0;
}
