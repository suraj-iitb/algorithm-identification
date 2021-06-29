#include<iostream>
using namespace std;

const int N = 100;

int bubble_sort(int n, int A[]) {
  int step = 0, flag = 1, sorted = 0;
  
  while (flag) {
    flag = 0;
    for (int i = n-1; i > sorted; i--) {
      if (A[i-1] > A[i]) {
        step++;
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flag = 1;
      }
    }
    sorted++;
  }

  return step;
}

int main() {
  int n;
  int A[N];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  int step = bubble_sort(n, A);
  
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << step << endl;

  return 0;
}

