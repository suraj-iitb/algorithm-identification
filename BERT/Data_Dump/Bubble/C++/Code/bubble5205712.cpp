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

int main(){
  int N;
  cin >> N;
  int A[N];

  for(int i=0; i < N ; i++){
    cin >> A[i];
  }
  bubbleSort(A,N);


  return 0;

}

