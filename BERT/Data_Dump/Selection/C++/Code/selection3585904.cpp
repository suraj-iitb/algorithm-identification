#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int num = 0;
  for(int i =0 ; i < n; i++){
    int minj = i;
    for(int j = i; j <n; j++) {
      if(A[j] < A[minj]) {
        minj = j;
      }
    }
    if(minj != i) {
        swap(A[i],A[minj]);
        num++;
      }
  }

  for(int i = 0; i < n; i++) {
    if(i) cout << " ";
    cout << A[i];
  }

  cout << endl;
  cout << num << endl;
}
