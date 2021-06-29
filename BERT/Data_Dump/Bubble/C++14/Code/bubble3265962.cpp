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

int bubbleSort(int A[], int N){
  int counter = 0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for(int j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
        int k = A[j];
        A[j] = A[j-1];
        A[j-1] = k;
        flag = 1;
        counter++;
      }
    }
  }

  return counter;
}

int main(){
  int N;
  int counter = 0;
  cin >> N;
  int res[N];
  for(int i=0;i<N;i++){
    res[i] = 0;
  }

  for(int i=0;i<N;i++){
    cin >> res[i];
  }

  counter = bubbleSort(res, N);
  display(res, N);
  cout << counter << endl;
}

