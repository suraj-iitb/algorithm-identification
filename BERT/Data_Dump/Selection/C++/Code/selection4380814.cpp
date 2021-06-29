#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void selectionSort(vector<int> &A, int N, int &count) {
  for(int i = 0; i <= N - 1; i++) {
    int minj = i;
    for(int j = i; j <= N - 1; j++) {
      if(A[j] < A[minj]) {
      	minj = j;
      }
    }
    if (minj != i) {
      swap(A[minj], A[i]);
      count ++;
    }
  }
}

int main() {
  int N;
  int count = 0;
  cin >> N;
  vector<int> A(N);
  rep (i, N) cin >> A.at(i);
  selectionSort(A, N, count);
  rep (i, N) {
    cout << A.at(i);
    if (i != A.size() - 1) {
    	cout << " ";
    }
  }
  cout << endl;
  cout << count << endl;
}
