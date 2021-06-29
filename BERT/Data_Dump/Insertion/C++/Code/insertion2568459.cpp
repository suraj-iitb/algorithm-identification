#include <iostream>

using namespace std;

void insertionSort(int*, int);
void trace(int*, int);

void insertionSort(int a[], int n){
  for(int i = 1; i < n; i++){
    int temp = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > temp){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
    trace(a, n);
  }
}

void trace(int a[], int n){
  for(int i = 0; i < n; i++){
    if(i>0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main(){
  int n;
  int a[100];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  trace(a, n);
  insertionSort(a, n);
  return 0;
}
