#include <bits/stdc++.h>
using namespace std;

void display(int A[], int N){
  for(int i=0;i<N;i++){
    if(i==N-1){
      cout << A[i];
    } else {
      cout << A[i] << " ";
    }
  }
  cout << endl;
}

void insertionSort(int A[], int N){
  for(int i=1;i<N;i++){
    int v = A[i];
    int j = i -1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    display(A, N);
  }
}

int main(){
  int N;
  cin >> N;

  int A[N];
  for(int i=0;i<N;i++){
    A[i] = 0;
  }

  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  display(A, N);
  insertionSort(A, N);

}

