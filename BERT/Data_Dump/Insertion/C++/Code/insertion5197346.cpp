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

int main(){
 int N;
 
 cin >> N;
 
 int A[N];
 
 for(int i=0; i < N ; i++){
     cin >> A[i];
 }

 intertionSort(A, N);

 return(0);
}
