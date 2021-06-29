#include<stdio.h>

int main()
{
  int A[1000];
  int N;
  int i,j,v,n;

  /* 入力 */
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 
  
  for(n=0;n<N;n++){
    if(n>0) printf(" ");
    printf("%d",A[n]);
  }
  printf("\n");
    

  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
      
    for(n=0;n<N;n++){
      if(n>0) printf(" ");
      printf("%d",A[n]);
    }
    printf("\n");
  }
  return 0;
}
   

