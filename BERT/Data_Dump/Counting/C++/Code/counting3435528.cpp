#include<iostream>
using namespace std;
#define MAX 10000

void countingSort(int A[], int B[], int n){
  int C[MAX];

  for ( int i = 0; i <= MAX; i++) C[i] = 0;
  // A[i]の個数をCのA[i]番目に記録
  for ( int i = 0; i < n; i++){
    C[A[i]]++;
  }

  // A[i]以下の数の個数をCのA[i]番目に記録
  for ( int i = 0; i <= MAX; i++){
    C[i+1] += C[i];
  }

  for ( int i = n-1; i >= 0; i--){
    // C[i]=0になることがないので、B[0]は空になる
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main(){
  int n;
  cin >> n;
  int A[n+1], B[n+1];
  for ( int i = 0; i < n; i++){
    cin >> A[i];
  }

  countingSort(A, B, n);

  for ( int i = 1; i <= n; i++){
    if( i-1 ) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}

