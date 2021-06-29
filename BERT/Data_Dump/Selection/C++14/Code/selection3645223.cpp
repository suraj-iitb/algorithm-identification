#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A[100], minj, cnt=0;
  cin >> N;
  for ( int i = 0; i < N; i++) cin >> A[i];
  for ( int i = 0; i < N; i++) {
    minj = i;
    for ( int j = i; j < N; j++)
      if ( A[j] < A[minj] ) minj = j;
    if ( i != minj ) {
      cnt++;
      swap(A[i], A[minj]);
    }
  }
  for ( int i = 0; i < N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}


/*
int selectionSort(int A[], int N) {
  int minj = 0;
  int sw = 0;
  for ( int i = 0; i < N; i++ ) {
    minj = i;
    for ( int j = i; i < N; j++ ) {
      if ( A[j] < A[minj] ) {
        minj = j;
      }
    }
    if ( i != minj ) {
      swap(A[i], A[minj]);
      // int tmp = A[i];
      // A[i] = A[minj];
      // A[minj] = tmp;
      sw++;
    }
  }
  cout << sw << endl;
  return sw;
}


int main() {
  int N, sw;
  cin >> N;
  // scanf("%d", &N);
  int A[N];
  for ( int i = 0; i < N; i++ ) cin >> A[i];

  sw = selectionSort(A, N);

  for ( int i = 0; i < N; i++ ) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
*/

