#include<stdio.h>
#define N 100
int bubbleSort(int *,int);
int main(){
  int A[N];
  int i,n,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
  }
  c = bubbleSort(A,n);
  for(i=0;i<n;i++) {
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

int bubbleSort(int *A,int n){
  int i,j,tmp,c=0;
  for(i = 0;i < n-1;i++) {
    for(j = n-1;j > i;j--) {
      if(A[j]<A[j-1]) {
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	c++;
      }
    }
  }
  return c;
}
