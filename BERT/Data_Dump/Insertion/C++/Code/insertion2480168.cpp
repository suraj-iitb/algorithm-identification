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

int main() {

  vector<int> A;
  int N;

  cin >> N;
  A.reserve(N);
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    A.push_back(v);
  }

  // Insertion sort
  for (int i = 1; i <= N; i++) {
    print(A, N);
    int v = A[i];
    int j = i - 1;
    while ((j >= 0) && (A[j] > v)) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }

  
  return 0;
}
