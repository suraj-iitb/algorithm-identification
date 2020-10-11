#include <stdio.h>
int main(){
  int i,j,minj,times=0,temp,N;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj=j;
    }

    if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      times++;
    }
  }

  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[N-1]);

  printf("%d\n",times);

  return 0;
}
