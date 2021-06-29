#include<stdio.h>
int main(){
  int a;
  int A[100];
  int j,i;
  int tmp;
  int count;
  scanf("%d",&a);
  for(i = 0;i < a;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0;i < a;i++){
    for(j = a-1;j >= 1;j--){
      if(A[j-1] > A[j]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	count++;
      }
    }
  }

  for(i = 0;i < a-1;i++){
    printf("%d",A[i]);
    if(i <= a-2){
      printf(" ");
    }
  }
  printf("%d\n",A[a-1]);
  printf("%d\n",count);
  return 0;
}

