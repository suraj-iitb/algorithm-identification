//warota!w

#include <stdio.h>
 
int N = 100;
 
void out(int A[], int n, int count){
  int i;
  for (i=0;i<n;i++){
    if (i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}
void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(int* A, int n){
  int j, count=0, flag=1;
  while(flag){
  	flag = 0;
  	for(j=n-1;j>=1;j--){
  		//printf("test1 j=%d\n", j);
  		//printf("j-1 = %d j =%d \n", A[j], A[j-1]);
  		if (A[j] < A[j-1]){
  			//printf("swap\n");
  			swap(&A[j], &A[j-1]);
  			flag=1; count++;
  		}
  	}
  }
  out(A, n, count);
}
 
int main(void){
  int n, i;
  int A[N+1];
  scanf("%d", &n);
 
  for (i=0;i<n;i++) scanf("%d", &A[i]); //data input
  bubbleSort(A, n);
 
  return 0;
}
