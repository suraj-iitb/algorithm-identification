#include <iostream>
#include <algorithm>
using namespace std;


void show(int A[], int N){
  for(int i=0; i<N; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  return;
}

int insertionSort(int A[], int N){
  for(int i=1; i<N; i++){
    int v = A[i];
    int j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    show(A, N);
  }
}

int main(){
  int N, A[1000];
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  show(A, N);
  insertionSort(A, N);
  return 0;
}
