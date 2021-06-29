#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N){
  int counter = 0;
  for(int i=0;i<N;i++){
    int minj = i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj = j;
      }
    }
    if(i != minj){
      int k=0;
      k = A[i];
      A[i] = A[minj];
      A[minj] = k;
      counter++;
    }
  }
  return counter;
}

int main(){
  int N;
  cin >> N;
  int vec[N];
  for(int i=0;i<N;i++){
    vec[i] = 0;
  }

  for(int i=0;i<N;i++){
    cin >> vec[i];
  }

  int counter = 0;
  counter = selectionSort(vec, N);

  for(int i=0;i<N;i++){
    if(i == N -1){
      cout << vec[i] << endl;
    } else {
      cout << vec[i] << " ";
    }
  }
  cout << counter << endl;
}

