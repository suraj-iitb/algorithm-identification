#include <stdio.h>
#define N 100
void Swap(int*x,int*y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
int main(){
  int i,j,n,count=0;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	Swap(&A[j],&A[j-1]);
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
