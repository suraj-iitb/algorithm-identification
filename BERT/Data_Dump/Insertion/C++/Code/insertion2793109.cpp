#include<iostream>

void insertionSort(int A[],int N){
  int v,j;
  for(int i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 and A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  int a[N]={0};
  for(int i=0;i<N;i++){
    std::cin>>a[i];
  }
  for(int j=1;j<=N;j++){
    insertionSort(a,j);
    for(int k=0;k<N-1;k++){
      std::cout<<a[k]<<" ";
    }
    std::cout<<a[N-1];
    std::cout<<'\n';
  }
  
  return 0;
}
