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

  int count = 0;

  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
        int t = A[j];
        A[j] = A[j - 1];
        A[j - 1] = t;
        count++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl << count << endl;
  return 0;
}
