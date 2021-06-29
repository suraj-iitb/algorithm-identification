#include <stdio.h>
#include <iostream>

using namespace std;

int bubbleSort(int *A, int N);
void display(int *A, int N);

int main(){
    int N;
    int A[100];
    int cnt;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cnt = bubbleSort(A, N);
    display(A, N);
    cout << cnt <<endl;
}

int bubbleSort(int *A, int N){
    int cnt=0;
    int flag = 1;
    while(flag){
        flag =0;
        for(int j=N-1; j>0; j--){
            if (A[j] < A[j-1]){
                int tmp;
                tmp =A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag = 1;
                cnt+=1;
            }
        }
    }
    return cnt;
}
void display(int *A, int N){
  for(int i=0; i<N-1 ;i++){
    cout <<A[i] << " ";
  }
  cout << A[N-1] << endl;
}

