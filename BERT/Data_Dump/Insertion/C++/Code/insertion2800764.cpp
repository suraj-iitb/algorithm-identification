#include<iostream>
void print_array(int A[],int N){
      for(int j=0;j<N;j++){
      std::cout<<A[j];
      if(j!=N-1) std::cout<<' ';
    }
    std::cout<<'\n';
}
int main(){
  int N;
  std::cin>>N;
  int A[N];
  for(int i=0;i<N;i++){
    std::cin>>A[i];
  }
    print_array(A,N);
  for(int i=1;i<=N-1;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    print_array(A,N);
  }
  return 0;
}
