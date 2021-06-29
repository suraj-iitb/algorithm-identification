#include<stdio.h>

int main(void){
  int key,N,mi,i,j,count=0;
  int A[100];

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N-1;i++){
    mi = i;
    for(j=i+1;j<N;j++){
      if(A[j]<A[mi]){
	mi=j;
      }
    }
    
    key=A[i];
    A[i]=A[mi];
    A[mi]=key;
    if(A[i]!=A[mi]) count++;   
  }
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  
  printf("\n%d\n",count);
  return 0;
}
