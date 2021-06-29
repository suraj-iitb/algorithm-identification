#include <iostream>
using namespace std;

void insertionSort(int n, int a[]) {
  for (int i=0;i<n-1;i++)
      cout << a[i] << " ";
    cout << a[n-1] << endl;
  for (int i=1;i<=n-1;i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    for (int i=0;i<n-1;i++)
      cout << a[i] << " ";
    cout << a[n-1] << endl;
  }
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i=0;i<n;i++)
    cin >> a[i];

  insertionSort(n, a);
}

