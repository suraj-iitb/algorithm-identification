#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
  int sw = 0, minj;
  for(int i = 0; i < N; i++){
    minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
  swap(A[i],A[minj]);
  //minj ?????´??°??????????????°???sw????????????????????????
  if ( i != minj ) sw++;
  }

  for(int i = 0; i < N; i++){
    if(i == N-1) cout << A[i] << endl;
    else cout << A[i] << " ";
  }

  return sw;
}


int main(){
  int N,A[100],sw;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sw = selectionSort(A, N);
  cout << sw << endl;

  return 0;
}
