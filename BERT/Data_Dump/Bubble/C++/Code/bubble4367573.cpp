#include <iostream>
#include <utility>
using namespace std;

void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void bubbleSort(int a[], int n) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        flag = true;
        count++;
      }
    }
  }
  printArray(a, n);
  cout << count << endl;
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bubbleSort(a, n);
}

