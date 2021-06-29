#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *,int);

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
    a = binarySearch(arrayS,arrayT[i]);
    count+=a;
  }
  
  printf("%d\n",count);

free(arrayS);
free(arrayT);

return 0;
}

int binarySearch(int arrayS[],int key){
  int i,left,right,mid;

  left = 0;
  right = N;
  
  while(left<right){
    mid = (left+right)/2;
    
    if(key == arrayS[mid]){
      return 1;
    }
    
    if(key>arrayS[mid]){
      left = mid + 1;
    }
    
    else if(key<arrayS[mid]){
      right = mid;
    }
  }
  return 0;
}
