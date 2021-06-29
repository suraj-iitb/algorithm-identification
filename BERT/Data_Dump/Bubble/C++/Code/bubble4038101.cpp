#include<stdio.h>
#include<cstdlib>

#define SWAP(a,b) (a += b,b = a - b,a -= b)

int main(){
  int i,j,N, *arr, flag = 1, count = 0,tmp;
  scanf("%d",&N);
  arr = (int *)malloc(sizeof(int) * N);
  for(i = 0; i < N; i++){
    scanf("%d",&arr[i]);
  }
  #ifdef D
  for(i = 0; i < N; i++){
    printf("%d ",arr[i]);
  }
  SWAP(count, flag);
  printf("%d\n",count);
  #endif

  // babbleSort
  i = 0; // first unsorted array index
  while(flag){
    flag = 0;
    for(j = N - 1; j > i; j--){
      if(arr[j - 1] > arr[j]){
	//SWAP(arr[j-i],arr[j]);
	tmp = arr[j];
	arr[j] = arr[j-1];
	arr[j-1] = tmp;
	flag = 1;
	count++;
      }
    }
    i++;
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
  

  return 0;
}

