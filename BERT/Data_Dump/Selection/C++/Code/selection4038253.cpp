#include<stdio.h>
#include<cstdlib>

int main(){
  int i,j,N,*arr,minj,tmp,count = 0;
  scanf("%d",&N);
  arr = (int *)malloc(sizeof(int) * N);
  for(i = 0; i < N; i++){
    scanf("%d",&arr[i]);
  }

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(arr[j] < arr[minj]){
	minj = j;
      }
    }
    tmp = arr[i];
    arr[i] = arr[minj];
    arr[minj] = tmp;
    if(i != minj) count++;
  }
  for(i = 0; i < N; i++){
    printf("%d",arr[i]);
    if(i == N-1){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",count);
  

  free(arr);
  return 0;
}

