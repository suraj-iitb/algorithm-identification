#include <iostream>
using namespace std;

void printArray(int* a, int n){
  for(int i = 0; i < n - 1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  
  return;
}

void insertionSort(int* a, int n){
  for(int i = 1; i < n; i++){
    int v = a[i];
    int j = i - 1;

    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    
    printArray(a, n);
  }  
  
  return;
}

int main() {
  int len;
  cin >> len;

  int a[len];
  for(int i = 0; i < len; i++) cin >> a[i];

  printArray(a, len);
  
  insertionSort(a, len);

  return 0;
}
