#include<iostream>
#include<vector>
using namespace std;

#define MAX 100

int main() {
  int n;
  int A[MAX];
  int count = 0;

  cin >> n;
  for (int i = 0; i < n; i++) { cin >> A[i]; }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        count++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << A[i];
    if (i == n - 1) cout << endl;
  }
  cout << count << endl;
}
