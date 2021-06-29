#include<iostream>
void insertionsort(int A[],int n){
  int v,j;
  for(int i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
      A[j+1]=v;
    for(int k=0;k<n;k++){
      std::cout<<A[k];
      if(k<n-1){
	std::cout<<" ";
      }
    }
    std::cout<<"\n";
  }
}

int main(){
  int N,a;
  int A[100]={0};
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>a;
    A[i]=a;
  }
  insertionsort(A,N);
  return 0;
}

