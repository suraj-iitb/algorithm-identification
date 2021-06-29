#include<stdio.h>
#include<iostream>
using namespace std;


void insertionSort(int *A, int N);
void display(int *A, int N);

int main(){
  int A[1000];
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  insertionSort(A, N);
}

void insertionSort(int *A, int N){
  for(int i=1; i< N; i++){
    display(A, N);
    int v, j;
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1] = v;
  }
  display(A, N);
}

void display(int *A, int N){
  for(int i=0; i<N-1 ;i++){
    cout <<A[i] << " ";
  }
  cout << A[N-1] << endl;
}
