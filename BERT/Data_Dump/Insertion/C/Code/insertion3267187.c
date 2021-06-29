#include<stdio.h>
#define N 100
int main(){
  int i, j, A[N], num,key;
  scanf("%d",&num);

  for(i = 0;i < num;i++){
    scanf("%d", &A[i]);
  }
  for(i = 0;i < num-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num - 1]);

  for(i = 1;i <= num-1;i++){
    key = A[i];
    j = i -1; 
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
  }
    for(j = 0;j < num-1;j++){
       printf("%d ",A[j]);
  }
    printf("%d\n",A[num-1]);
  }
  
  return 0;
}

