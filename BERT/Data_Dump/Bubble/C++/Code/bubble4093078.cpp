#include <iostream>
using namespace std;
void printArray(const int *A, int N){
    for(int i=0; i<N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
}

void bubbleSort(int *A, int N){
  int flag = 1;
  int count = 0;
  while(flag == 1){
    flag = 0;
    for(int j=N-1; j>0; j--){
      if(A[j] < A[j-1]){
        int temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        flag = 1;
        count ++;
      }
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
    bubbleSort(A, x);
    delete A;
}
