#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> a, int n) {
  for (int k = 0; k < n; ++k) {
    cout << a.at(k) << ((k == n - 1) ? "\n" : " ");
  }
}

void insertionSort(vector<int> a, int n) {
  for (int i = 1; i < n; ++i) {
    int v = a.at(i);
    int j = i - 1;
    while (j >= 0 && a.at(j) > v) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = v;
    printVector(a, n);
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a.at(i);
  }
  printVector(a, n);
  insertionSort(a, n);
  return 0;
}

