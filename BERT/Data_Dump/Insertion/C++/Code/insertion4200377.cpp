#include <iostream>
using namespace std;

void trace(int a[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void insertionSort(int a[], int N) {
  for (int i = 1; i < N; i++) {
    int v = a[i];
    int j = i-1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    trace(a, N);
  }
}

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  trace(a, N);
  insertionSort(a, N);
}

