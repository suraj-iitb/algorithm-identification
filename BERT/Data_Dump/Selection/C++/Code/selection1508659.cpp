#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int selectionSort(int A[], int N){
  int i, j, minj, cnt = 0;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj])  minj = j;
    }
      if(i != minj){
        swap(A[i], A[minj]); 
        cnt++;
      }
  }

  return cnt;
}

int main(){
  int N, A[100], cnt, i;
  
  cin >> N;
  for(i = 0; i < N; i++) cin >> A[i];

  cnt = selectionSort(A, N);

  for(i = 0; i < N; i++){
    if(i){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl; 
}
