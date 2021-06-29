#include <iostream>

using namespace std;

static const int MAX = 100;

int main () {

  int N, A[MAX];

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool flag = 1;
  int count = 0;

  for (int i = 0; flag; i++) {
    flag = 0;

    for (int j = N-1; i < j; j--) {
      if (A[j] < A[j-1]) {
        int a = A[j-1];
        A[j-1] = A[j];
        A[j] = a;
        flag = 1;
        count ++;
      }
    }

  }

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }

  cout << endl;
  cout << count << endl;


}
