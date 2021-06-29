#include<stdio.h>

int main()
{
  int N,A[100],i,v,j,a,k;
  scanf("%d",&N);
  for(a=0;a<N;a++){scanf("%d",&A[a]);
  }
  for (i=1;i<N+1;i++){
    for(k=0;k<N-1;k++)
      printf("%d ",A[k]);
    for(k=N-1;k<N;k++){
      printf("%d",A[k]);}
    printf("\n");
    v = A[i];
    j = i - 1;
    
  while(j>=0&&A[j]>v){
    A[j+1] = A[j];
    j--;
  
    A[j+1] = v;
  }
  }
  
 
  return 0;
}
  

