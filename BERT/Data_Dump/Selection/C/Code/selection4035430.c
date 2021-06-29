#include<stdio.h>
int selectionsort(int *,int);

int main(){
  int n,count,A[100],i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
    count=selectionsort(A,n);
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j==n-1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n",count);
  return 0;
}

int selectionsort(int *A,int x){
  int i,j,minj,z,count=0;
  for(i=0;i<x-1;i++){
    minj=i;
    for(j=i;j<x;j++){
      if(A[j]<A[minj])
	minj=j;
    }
    z=A[i];
    A[i]=A[minj];
    A[minj]=z;
    if(i!=minj)
      count++;
  }
  return count;
}

