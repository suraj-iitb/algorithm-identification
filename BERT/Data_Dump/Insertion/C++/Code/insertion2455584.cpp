#include<iostream>
#include<algorithm>
using namespace std;

int insertionSort(int A[], int N){
  int v, j;
  for (int i = 1; i < N; i++){

    v = A[i];

    j = i -1;
    for (; j >= 0 && A[j] > v; j--){
      A[j+1] = A[j];
    }

    A[j+1] = v;

    //??????
    for (int i = 0; i < N; i++){
      if(i == N-1) cout << A[i] << endl;
      else cout << A[i] << " ";
    }

  }
  return 0;
}


int main(){
  int N, A[1000];
  cin >> N;
  for ( int i = 0; i < N; i++) cin >> A[i];
  //????????????
  for (int i = 0; i < N; i++){
    if(i == N-1) cout << A[i] << endl;
    else cout << A[i] << " ";
  }
  insertionSort(A, N);

  return 0;
}
