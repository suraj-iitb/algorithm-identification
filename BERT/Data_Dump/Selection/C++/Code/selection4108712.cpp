#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100

int main() {
  int n;
  int A[MAX];
  int count = 0;

  cin >> n;
  for (int i = 0; i < n; i++) { cin >> A[i]; }

  for (int i = 0; i < n - 1; i++) {
    int min_key = i;
    for (int j = i; j < n; j++) {
      if (A[j] < A[min_key]) min_key = j;
    }
    if (min_key != i) {
      int t = A[i]; A[i] = A[min_key]; A[min_key] = t;
      count++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << A[i];
    if (i == n - 1) cout << endl;
  }
  cout << count << endl;
}
