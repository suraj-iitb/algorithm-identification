#include<stdio.h>

int main(){
  int N,i,j,k,A[100],a,min,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    min=i;
    
    for(j=i;j<N;j++){
      if(A[j]<A[min]) min=j;	
    }
       
    if(min!=i){
      a=A[i];
      A[i]=A[min];
      A[min]=a;
      count++;
    }
  }
 
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}

