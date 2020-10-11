#include <stdio.h>
#define N 100

void swap(int *,int *);

int main(){
  int n,A[N];
  int i,j,flag=0,change=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	change++;
	flag=1;
      }
    }
    i++;
  }
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  if(i==n-1)printf("%d\n",A[i]);
  printf("%d\n",change);
  return 0;
}

void swap(int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
