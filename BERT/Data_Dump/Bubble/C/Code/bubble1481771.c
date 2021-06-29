#include <stdio.h>
#include <string.h>
#define N 100


int main(void){
  int flag,A[N],i,j,n,v,count=0;

  scanf("%d",&n);

  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }

  flag = 1;
  i = 0;
 
  flag = 0;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){   
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	count++;
	flag = 1;
      }
    }
  }
    for(j=0;j<n-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d", A[n-1]);
    printf("\n");
    printf("%d\n",count);

    return 0;
  }
