#include <stdio.h>
void swap(int *,int *);

int main(){
  int i,j,n,A[100],c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	c++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

void swap(int *a,int *b){
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
