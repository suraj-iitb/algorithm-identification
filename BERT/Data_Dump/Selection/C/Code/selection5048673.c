#include<stdio.h>
void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
void Select(int A[],int n){
  int i,j,k,minj,count=0;
  for(i=0;i<=n-2;i++){
    minj = i;
    for(j =i;j <= n-1;j++){
      if(A[j]<A[minj]){
	minj = j;

      }
    }
    if(A[minj] < A[i]) count++;
    swap(&A[i],&A[minj]);
  }
  for(k=0;k < n;k++){
    if(k > 0) printf(" ");
    printf("%d",A[k]);
  }
    printf("\n%d\n",count);
}
int main(){
  int A[100],n,i;

  scanf("%d",&n);
  for(i=0; i < n; i++)  scanf("%d",&A[i]);
  Select(A,n);
  return 0;
}

