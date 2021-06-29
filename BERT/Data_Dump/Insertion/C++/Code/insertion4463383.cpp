#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> A) {
  for (int i = 0; i < A.size() - 1; ++i) {
    cout << A[i] << " ";
  }
  cout << A.back() << endl;
}

vector<int> insertionSort(vector<int> A) {
  for (int i = 1; i < A.size(); ++i) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = v;
    printVector(A);
  }
  return A;
}

int main() {
  int N;
  cin >> N;
  vector<int> A;
  int a;
  while(cin >> a) {
    A.push_back(a);
  }
  printVector(A);
  insertionSort(A);
}
