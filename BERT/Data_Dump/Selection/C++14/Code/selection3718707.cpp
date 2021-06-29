#include <iostream>
#include <vector>
using namespace std;
int a[100];

int selectionSort(int a[], int n) {
  int count = 0, tmp;
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;
    }
  }
  return count;
}
int main(int argc, char *argv[]) {
  int n, num = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  num = selectionSort(a, n);
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i != n - 1)
      cout << " ";
    else
      cout << "\n";
  }
  cout << num << endl;
  return 0;
}
