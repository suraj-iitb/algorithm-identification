#include <iostream>
using namespace std;

int selectionSort(int a[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    swap(a[i], a[minj]);
    if (i != minj) count++;
  }
  return count;
}

void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sw = selectionSort(a, n);
  printArray(a, n);
  cout << sw << endl;
}
