#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *,int);

int N,M;

int main(){
  int count=0,a;
  int i,*arrayS,*arrayT;
  
  scanf("%d",&N);
  arrayS = (int *)malloc(sizeof(int) * N);
  for(i=0;i<N;i++){
    scanf("%d",&arrayS[i]);
  }

  scanf("%d",&M);
  arrayT = (int *)malloc(sizeof(int) * M);
  for(i=0;i<M;i++){
    scanf("%d",&arrayT[i]);
  }

  for(i=0;i<M;i++){
    a = linearSearch(arrayS,arrayT[i]);
    count+=a;
  }
  
  printf("%d\n",count);

free(arrayS);
free(arrayT);

return 0;
}

int linearSearch(int arrayS[],int key){
  int i;

  for(i=0;i<N;i++){
    if(arrayS[i] == key) return 1;
  }
  return 0;
}
