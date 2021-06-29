#include<stdio.h>

void F(int*,int);
void A(int*,int);




  
  int main(){
  int N,i,j,v;
  int S[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&S[i]);
  }
 
  F(S,N);
  A(S,N); 
  return 0;
}
  
void F(int S[], int N){
  int i;

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
}
void A(int S[], int N){
  int j,i,v;
 
  for(i=1;i<N;i++){
    v =S[i];
    j=i-1;
  
    while(j>=0&&S[j]>v){
      S[j+1]=S[j];
      j--;
    }
 
    S[j+1]=v;
    F(S,N);
  }



}

