#include <stdio.h>
#include <iostream>

using namespace std;

int selectSort(int *A, int N);
void display(int *A, int N);

int main(){
    int N;
    int A[100];
    int cnt;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cnt = selectSort(A, N);
    display(A, N);
    cout << cnt <<endl;
}

int selectSort(int *A, int N){
    int cnt=0;
    for(int i=0; i<N; i++){
        int minj =i;
        for(int j=i; j<N; j++){
            if (A[j] < A[minj]) minj=j;
        }
        if(minj!=i) cnt+=1;
        int tmp;
        tmp=A[i];
        A[i]=A[minj];
        A[minj]=tmp;
    }
    return cnt;
}
void display(int *A, int N){
  for(int i=0; i<N-1 ;i++){
    cout <<A[i] << " ";
  }
  cout << A[N-1] << endl;
}
