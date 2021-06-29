#include <stdio.h>

int main(void)
{
 int v,i,j,count=0,min,A[100],N;

 scanf("%d",&N);

 for(i=0;i<N;i++){
  scanf("%d",&A[i]);
 }

 for(i=0;i<N;i++){
  min=i;
  for(j=i;j<N;j++){
    if(A[j]<A[min]){
      min=j;
    }
  }
 if(i!=min){
   v=A[i];
   A[i]=A[min];
   A[min]=v;
   count++;
  }
 }

 for(i=0;i<N-1;i++){
  printf("%d ",A[i]);
 }
 printf("%d\n",A[N-1]);
 printf("%d\n",count);

 return 0;

}
