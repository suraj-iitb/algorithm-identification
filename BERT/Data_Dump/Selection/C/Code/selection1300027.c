#include <stdio.h>
#include <string.h>
#define N 100


int main(void){
  int flag,A[N],i,j,n,v,count=0,minj;

  scanf("%d",&n);

  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }

  flag = 1;
  i = 0;
 
  flag = 0;
  for(i=0;i<n;i++){
    minj =i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){   
	minj = j;

      }
    }
    if(minj==i) continue;
    v=A[i];
    A[i]=A[minj];
    A[minj]=v;
    count++;
    flag = 1;
    
  }
  for(j=0;j<n-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d", A[n-1]);
  printf("\n");
  printf("%d\n",count);

  return 0;
}
