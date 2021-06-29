#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void Print(int *A, int N){
  for(int i=0; i < N ; i++){
    cout << A[i];
    if(i == N-1){
        cout << endl;
    }else{
        cout << " ";
    }
  }
  return;
}

//ALDS1_1
void intertionSort(int *A, int N){
  Print(A, N);
  for(int i=1; i <= N-1 ; i++){
      int v = A[i];
      int j = i - 1;

      while((j >= 0) && (A[j] > v)){
          A[j+1] = A[j];
          j--;
      }
      A[j+1] = v;
      Print(A, N);
  }
}

//ALDS1_2_A
void bubbleSort(int *A, int N){
    int flag = 1;
    int cnt = 0;
    while(flag){
        flag = 0;
        for(int j=N-1; j > 0; j--){
            if(A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    Print(A,N);
    cout << cnt << endl;
    return;
}

//ALDS1_2_B
void SelectionSort(int *A, int N){

  int cnt = 0;
  for(int i=0; i < N; i++){
    int minj = i;
    int flag = 0;
    for(int j=i; j < N; j++){
      if(A[j] < A[minj]){
        //cout <<  i << "_" << j << " swap " << A[minj] <<" " <<  A[j] << endl;
        minj = j;
        flag = 1;
      }
    }
    if(flag){
      cnt++;
    }
    int tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;   
  }
  Print(A,N);
  cout << cnt << endl;
  return;
}

int main(){
  int N;
  cin >> N;
  int A[N];

  for(int i=0; i < N ; i++){
    cin >> A[i];
  }
  //intertionSort(A,N);
  //bubbleSort(A,N);
  SelectionSort(A,N);

  return 0;

}

