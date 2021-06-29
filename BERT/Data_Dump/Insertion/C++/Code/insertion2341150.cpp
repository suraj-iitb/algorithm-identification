#include <iostream>
#include <cassert>
#include <queue>

#define INF 922337203685477580
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int s = 0; s < N - 1; s++) {
    cout << A[s] << " ";
  }
  cout << A[N - 1] << endl;

  for (int i = 1; i < N; i++) {
    int key = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

    for (int s = 0; s < N - 1; s++) {
      cout << A[s] << " ";
    }
    cout << A[N - 1] << endl;
  }

  return 0;
}
