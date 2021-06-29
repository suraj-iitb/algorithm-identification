#include <stdio.h>

int main(){
  int A[100],i,j,minj,temp,N,count=0,n;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])minj=j;
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj) count++;
  }

  for(n=0;n<N-1;n++){
    printf("%d ",A[n]);
  }
   printf("%d",A[N-1]);
   printf("\n%d\n",count);

  return 0;
}
