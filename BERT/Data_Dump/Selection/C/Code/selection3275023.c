#include <stdio.h>
#define MAX 100

int main (){
  int i,j,n,cnt = 0,tmp,minj,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(minj!=i)cnt++;
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }
  
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

