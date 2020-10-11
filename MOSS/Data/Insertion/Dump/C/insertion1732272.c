#include<stdio.h>

int main(){

  int N,i,j,v,A[1001];

  scanf("%d",&N); /*Input value of N*/

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);/*Input value of A[]*/
 
  for(j=0;j<N-1;j++)
    printf("%d ",A[j]);
  
  printf("%d\n",A[j]);


  for(i=1;i<N;i++){/*From 1 to N-1*/
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
      }
  
    for(j=0;j<N-1;j++)
      printf("%d ",A[j]);
    
    printf("%d\n",A[j]);
  }

  return 0;
}
