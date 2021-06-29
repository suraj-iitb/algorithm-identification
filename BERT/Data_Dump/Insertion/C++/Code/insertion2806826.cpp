#include<iostream>
void insertionSort(int A[],int N){
  int i,j,key;
  for(i=1; i<N; i++){
      key=A[i];
      j=i-1;
      while(j>=0 && A[j]>key){
	A[j+1] = A[j];
	j--;
      }
      A[j+1] = key;
  }
}
int main(){
  int N;
  std::cin>>N;

  int A[N]={0};
  int i,j;
  for(i=0; i<N; i++){
      std::cin>>A[i];
  }
  for(j=1; j<=N; j++){
    insertionSort(A,j); 
    for(i=0; i<N-1; i++){
      std::cout<<A[i]<<" ";
    }
    std::cout<<A[N-1];
    std::cout<<"\n";
  }
  return 0;
}
