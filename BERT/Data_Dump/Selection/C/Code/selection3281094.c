#include <stdio.h>
#define N 100
int selectionsort(int *,int);
int main(){
  int n,A[N],i,j,count;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
 count =  selectionsort(A,n);
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

int  selectionsort(int *A,int n){
  int i,j,p,tmp,count=0;
  for(i=0;i<n;i++){
    p = i;
    for(j=i;j<n;j++){
      if(A[j]<A[p]){
	p = j;
      }
    }
    if(p!=i){
      tmp=A[i];
      A[i]=A[p];
      A[p]=tmp;
    count++;
    }
  }
  return count;
}

