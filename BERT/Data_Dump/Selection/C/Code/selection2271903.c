#include<stdio.h>
#define N 100
int selectionSort(int *,int);
int main(){
  int A[N];
  int i,n,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
  }
  c = selectionSort(A,n);
  for(i=0;i<n;i++) {
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

int selectionSort(int *A,int n) {
  int i,j,tmp,minj,c=0;
  for(i = 0;i < n;i++) {
    minj = i;
    for(j = i;j < n;j++) {
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    if(i != minj){
    	tmp = A[i];
	A[i] = A[minj];
	A[minj] = tmp;
	c++;
    }
  }
  return c;
}
