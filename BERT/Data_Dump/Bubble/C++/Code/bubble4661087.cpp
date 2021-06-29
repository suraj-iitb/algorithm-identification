#include<iostream>
using namespace std;

void trace(int A[], int N){
  for ( int i = 0; i < N; i++ ){
    if ( i > 0 ) cout << " ";
    cout << A[i];
  }
  cout << "\n";
}

void bubbleSort(int A[], int N){
  int v, i = 0, flag = 1, cnt = 0;

  while(flag){
    flag = 0;
    for ( int j = N-1; j > i; j-- ){
      if ( A[j-1] > A[j] ){
        v = A[j];
        A[j] = A[j-1];
        A[j-1] = v;
        cnt++;
        flag = 1;
      }
    }
    i++;
  }

  trace(A, N);
  cout << cnt << endl;
}

int main(){
  int N, A[100];

  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];

  bubbleSort(A, N);

  return 0;
}
