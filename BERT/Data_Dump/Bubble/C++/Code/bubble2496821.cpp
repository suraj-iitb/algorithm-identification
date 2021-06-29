#include <iostream>
#include <vector>

using namespace std;
using std::vector;

#define MAX_N 100

void print(vector<int>& A, int N) {
  for (int i = 0; i < N - 1; i++)
    cout << A[i] << " ";
  cout << A[N-1] << endl;
}

int bubbleSort(vector<int>& A, int N) {
  int sw = 0;
  bool flag = true;
  for (int i = 0; flag; ++i) {
    flag = false;
    for (int j = N - 1; j >= 1; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        flag = true;
        sw++;
      }
    }
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

  sw = bubbleSort(A, N);
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl
       << sw << endl;
  return 0;
}
