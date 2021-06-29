#include<stdio.h>
#define MAX 100

void sort(int A[],int n){
  int i,j;
  int v,c=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	c++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",c);
  
}

main(){
  int n;
  int i;
  int A[MAX];
  
  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  sort(A,n);

  return 0;
}

