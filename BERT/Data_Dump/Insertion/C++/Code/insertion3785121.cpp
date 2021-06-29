#include <iostream>
using namespace std;

void insertionSort(int a[], int n);
void displayArray(int a[], int n);

int main() {
  int a[100], n;
  int v,j;
  cin >> n;
  for(int i = 0; i < n; i++) cin>>a[i];
  displayArray(a, n);
  insertionSort(a, n);
  return 0;
}

void insertionSort(int a[], int n) {
  int v,j;
  for(int i = 1; i < n; i++) {
    v = a[i];
    j = i -1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    displayArray(a, n);
  }
}

void displayArray(int a[], int n) {
  for(int i = 0; i < n; i++) {
    cout << a[i];
    if(i == n-1) cout << "\n";
    else cout << " ";
  }
}
