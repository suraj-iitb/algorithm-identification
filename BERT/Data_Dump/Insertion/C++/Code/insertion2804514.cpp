#include<iostream>

int main(){

  int N,v,j;

  std::cin>>N;

  int A[N];

 for(int i=0;i<N;i++){
   std::cin>>A[i];
  }

 for(int i=0;i<N;i++){
   if(i==N-1){
     std::cout<<A[i];
   }else{
   std::cout<<A[i]<<" ";
   }
 }

 std::cout<<"\n";

  for(int i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){

      A[j+1]=A[j];
      j--;
    }
 A[j+1]=v;

      for(int k=0;k<N;k++){
 if(k==N-1){
     std::cout<<A[k];
   }else{
   std::cout<<A[k]<<" ";
   }
}
      std::cout<<"\n";
    }
 
  return 0;
}
