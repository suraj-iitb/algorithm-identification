#include <iostream>
using namespace std;

void print_array(int a[], int n) {
  cout << a[0];
  for (int i = 1; i < n; i++) {
    cout << " " << a[i];
  }
  cout << endl;
}

void insertion_sort(int a[], int n) {
  print_array(a, n);
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    print_array(a, n);
  }
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  insertion_sort(a, n);
}
