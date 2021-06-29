#include<iostream>
using namespace std;

void trace(int A[],int N){
  int i;
  for (i=0;i<N;i++){
    if (i>0) std::cout << " ";
    cout << A[i];
  }
  cout << '\n';
}

void InsertionSort(int A[],int N){
  int v,i,j;
  for (i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    trace(A,N);
    }
  }


int main(){
  int N;
  cin>>N;
  int A[N],i;
  for (int i=0;i<N;i++) std::cin>>A[i];

  trace(A,N);
  InsertionSort(A,N);

  return 0;
}

