#include<stdio.h>

int selectionSort(int* ,int);

  
int main(){
  int n,cnt,i;
  int value[100];
  
  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&value[i]);
  }

  cnt = selectionSort(value,n);

  for(i = 0;i < n;i++){
    printf("%d",value[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;

}

int selectionSort(int *A ,int n){
  int i,j,minj,tmp,cnt = 0;

  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i != minj){
	tmp = A[i];
	A[i] = A[minj];
	A[minj] = tmp;
	cnt++;
    }
  }
  return cnt;
}
  
