#include<iostream>
using namespace std;

void bubbleSort(int A[], int N){
  int flag, t, change_num = 0;

  flag = 1;
  for(; flag;){
    flag = 0;
    for(int j = N-1; j > 0; j--){
      if (A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
        flag = 1;
        change_num += 1;
      }
    }
  }
  for(int i = 0; i < N; i++){
    if(i == N-1) cout << A[i] << endl;
    else cout << A[i] << " ";
    }
  cout << change_num << endl;
}

int main(){
  int N,A[100];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  bubbleSort(A, N);

  return 0;
}
