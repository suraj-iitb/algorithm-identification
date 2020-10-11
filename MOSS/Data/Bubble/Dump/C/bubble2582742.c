#include <stdio.h>

int main(void)
{
 int count=0,v,i,j,N,A[100],flag=1;

 scanf("%d",&N);

 for(i=0;i<N;i++){
  scanf("%d",&A[i]);
 }

 i=0;

 while(flag){
  flag=0;
  for(j=N-1;j>i;j--){
   if(A[j]<A[j-1]){
     v=A[j];
     A[j]=A[j-1];
     A[j-1]=v;
     flag=1;
     count++;
   }
  }
  i++;
 }
 for(i=0;i<N-1;i++){
  printf("%d ",A[i]);
 }
 printf("%d\n",A[N-1]);
 printf("%d\n",count);

 return 0;
}
  
     
