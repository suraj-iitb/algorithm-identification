#include <stdio.h>
#define N 100

int main(){
  int i,j,n,A[N],minj,st,co=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj = i;
    
    for(j=i;j<n;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i]!=A[minj]) co += 1;
    st = A[minj];
    A[minj] = A[i];
    A[i] = st;
  }
  for(i=0;i<n;i++){
    if(i != n-1) printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",co);
  return 0;
}

