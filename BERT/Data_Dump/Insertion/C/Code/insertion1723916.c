#include <stdio.h>
int main()
{
  int array[1000];
  int i,j,key,N,k;

  scanf("%d",&N);
  for(i=0;i<N;i++){
  scanf("%d",&array[i]);
  }
  for(i=0;i<N-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d",array[N-1]);
  printf("\n");
  for(i=1;i<=N-1;i++){
    key=array[i];
    j=i-1;
    while(j>=0&&array[j]>key){
      array[j+1]=array[j];
      j--;
      array[j+1]=key;
    }
    for(k=0;k<N-1;k++){
      printf("%d ",array[k]);
    }
    printf("%d",array[N-1]);
    printf("\n");
  }

  return 0;
}
