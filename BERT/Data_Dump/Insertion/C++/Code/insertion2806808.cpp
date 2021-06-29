#include<iostream>

void InsertionSort(int N,int A[]){
  int v;
  int i,j;
  for(i=1; i<N; i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }
}

int main()
{
  int N;
  int i,j;
  int A[100]={0};
  std::cin>>N;
  for(i=0; i<N; i++){
    std::cin>>A[i];
  }
  for(i=1; i<=N; i++){
    InsertionSort(i,A);
    for(j=0; j<N-1; j++){
      std::cout<<A[j]<<" ";
    }
    std::cout<<A[N-1];
    std::cout<<'\n';
  }
  return 0;
}
