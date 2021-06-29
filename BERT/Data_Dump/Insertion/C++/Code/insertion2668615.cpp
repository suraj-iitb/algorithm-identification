#include <iostream>
using namespace std;

void trace(int A[], int N){
  int i;
  for(i=0;i<N;i++){
    if(i) cout<<" ";
    cout << A[i];
  }
  cout << endl;
}

void insertionSort(int A[], int N){
  int i,j,v;
  for(i=1;i<N;i++){
    v=A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j --;
    }
    A[j+1]=v;
    trace(A,N);
  }
}

int main() {
  int N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++) cin>>A[i];
  trace(A,N);
  insertionSort(A,N);
}
