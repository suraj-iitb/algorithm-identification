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
    int mini = i;

    for (int j = i + 1; j < N; j++) {
      if (A[j] < A[mini]) {
        mini = j;
      }
    }

    if (mini != i) {
      int t = A[i];
      A[i] = A[mini];
      A[mini] = t;
      count++;
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
