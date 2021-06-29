#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
  int number = 0;
  for(int i = 0; i < N; i++){
    int minj = i;
    for (int j = i+1; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if (i!= minj){
      swap(A[i], A[minj]);
      number++;
    }
  }

  return number;
}

int main(){
  int A[100], N, number;

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  number = selectionSort(A, N);
  
  for(int i = 0; i < N; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << number << endl;
  return 0;
}

