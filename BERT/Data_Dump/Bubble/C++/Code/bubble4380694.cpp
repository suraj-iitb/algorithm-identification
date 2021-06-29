#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void bubbleSort(vector<int> &A, int N, int &count) {
  bool flag = 1;
  while (flag) {
  	flag = 0;
    for(int j = N - 1; j >= 1; j--){
      if(A[j] < A[j-1]) {
      	int tmpJ = A[j];
        A[j] = A[j -1];
        A[j - 1] = tmpJ;
        flag = 1;
        count ++;
      }
    }
  }
}

int main() {
  int N;
  int count = 0;
  cin >> N;
  vector<int> A(N);
  rep (i, N) cin >> A.at(i);
  bubbleSort(A, N, count);
  rep (i, N) {
    cout << A.at(i);
    if (i != A.size() - 1) {
    	cout << " ";
    }
  }
  cout << endl;
  cout << count << endl;
}
