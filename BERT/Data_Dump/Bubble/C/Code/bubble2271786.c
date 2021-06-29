#include<stdio.h>

int bubbleSort(int* ,int);

  
int main(){
  int n,cnt,i;
  int value[100];
  
  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&value[i]);
  }

  cnt = bubbleSort(value,n);

  for(i = 0;i < n;i++){
    printf("%d",value[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;

}
int bubbleSort(int *A,int n){
  int i,j,tmp,cnt = 0;

  for(i = 0; i < n - 1;i++){
      for(j = n - 1; j > i;j--){
	if(A[j] < A[j-1]) {
	  tmp = A[j];
	  A[j] = A[j-1];
	  A[j-1] = tmp;
	  cnt++;
	}
      }
    }
  return cnt;
	}
