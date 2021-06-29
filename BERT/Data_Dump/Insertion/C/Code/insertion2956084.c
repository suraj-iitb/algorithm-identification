#include<stdio.h>
int main(){
  int i=0,j=0,v,N=15,k=0,l;
  int A[125];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
     }
  for(i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1] = v;

    for(l=0;l<N;++l){
      if(l!=N-1){
      printf("%d",A[l]);
      printf(" ");}
      if(l==N-1&&i!=N-1){
        printf("%d",A[l]);
      }
      if(l==N-1&&i==N-1){
        printf("%d",A[l]);
      }

    }
    printf("\n");
  }

  return 0;
}


