#include <iostream>

using namespace std;
void printArray(const int *A, int N){
    for(int i=0; i<N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
}

void selectionSort(int *A, int N){
  int count = 0;
  for(int i=0; i<N; i++){
    int minj = i;
    for(int j=i; j<N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(minj != i){
      swap(A[i], A[minj]);
      count ++;
    }
  }
  printArray(A, N);
  cout << count << endl;
}

int main(){
    int x;
    cin >> x;
    int* A = new int[x];
    for(int i=0; i<x; i++){
        cin >> A[i];
    }
    selectionSort(A, x);
    delete A;
}
