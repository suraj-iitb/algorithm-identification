#include<bits/stdc++.h>
using namespace std;

int selectionSort (int A[], int N){
  int i,j,t,sw =0,minj;
  for (i = 0; i < N-1; i++){ //A[i]が未ソート部分の先頭
    minj =i;
    for( j= i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if(i != minj)sw++;
  }
  return sw;  
}

int main(){
  int N;
  cin >> N;
  int A[110];
  for(int i = 0; i <N; i++) cin >> A[i];
  
  int sw = 0;
  sw = selectionSort(A,N);
  
  for(int i = 0; i < N ; i++){
    cout << A[i];
    if(i != N-1) cout << " ";
  }
  cout << endl;
  cout << sw << endl;
}
