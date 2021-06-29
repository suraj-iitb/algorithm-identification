#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> A) {
  // 配列の中身を出力
  for (int i = 0; i < A.size(); i++) {
    cout << A.at(i);
    if (i < A.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  return;
}

void insertionSort(vector<int> &A) {
  int i, j, v;
  for (i = 1; i < A.size(); i++) {
    v = A.at(i);
    j = i - 1;
    while (j >= 0 && A.at(j) > v) {
      A.at(j + 1) = A.at(j);
      j--;
    }
    A.at(j + 1) = v;
    printVector(A);
  }
  return;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < A.size(); i++) {
    cin >> A.at(i);
  }

  printVector(A);
  insertionSort(A);

  return 0;
}
