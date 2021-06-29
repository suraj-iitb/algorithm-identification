#include<iostream>

void insertionSort(int A[],int N){

  int v,j;

  for(int i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }

    for(int k=0;k<N;k++){
      if(k>0) std::cout<<' ';
      std::cout<<A[k];
    }
    
    std::cout<<'\n';

  }
}

int main(){
  int N;
  int A[1000];
  
  std::cin>>N;

  for(int i=0;i<N;i++){
    std::cin>>A[i];
  }

  insertionSort(A,N);

  return 0;
}
