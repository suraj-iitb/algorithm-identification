#include<iostream>

using namespace std;

static const int MAXN = 100;

int main() {
  int n, A[MAXN];

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (int l = 0; l < n; l++) {
    /* code */
    if (l > 0) {
      cout << " ";
    }
    cout << A[l];
  }
  cout << endl;

  for (int i = 1; i < n; i++) {

    int j = i - 1;
    int value = A[i];

    while (j >= 0 && value < A[j]) {
        A[j+1] = A[j];
        A[j] = value;
      j--;
    }

    for (int l = 0; l < n; l++) {
      /* code */
      if (l > 0) {
        cout << " ";
      }
      cout << A[l];
    }
    cout << endl;
  }

}
