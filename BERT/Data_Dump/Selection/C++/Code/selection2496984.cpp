#include <iostream>
#include <vector>

using namespace std;
using std::vector;

#define MAX_N 100

int selectionSort(vector<int>& A, int N) {
  int minj = 101;
  int sw = 0;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj])
        minj = j;
    }
    if (i != minj)
      sw++;
    swap(A[i], A[minj]);
  }
  return sw;
}


int main() {

  vector<int> A;
  int N, sw;

  cin >> N;
  A.reserve(N);
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    A.push_back(v);
  }

  sw = selectionSort(A, N);
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl
       << sw << endl;
  return 0;
}
