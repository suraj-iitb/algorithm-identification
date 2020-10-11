#include <stdio.h>
 
int main(){
  int N,A[100],i,k,j,key;
  scanf("%d",&N);
  
  for(i=0;i<N;i++) scanf("%d",&A[i]);
 for(i=0;i<N-1;i++) printf("%d ",A[i]);
 printf("%d\n",A[N-1]);
 for(j=1;j<N;j++){
   key=A[j];
  i=j-1;
  while (i>-1 && A[i]>key){
    A[i+1]=A[i];
i--;
}
  A[i+1]=key;
for(k=0;k<N-1;k++) 
printf("%d ",A[k]);
 printf("%d\n",A[N-1]);
}
 
return 0;
}
