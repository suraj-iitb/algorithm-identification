#include <stdio.h>
#define N 100

int main(){

  int n,A[N],i,j,k,count=0,flag,temp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  
  while(flag){
    flag=0;

    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	count++;
      }

    }
    
  }

  for(k=0;k<n;k++){
    if(k)printf(" ");
    printf("%d",A[k]);
    
  }

  printf("\n");

  printf("%d\n",count);

  return 0;
}

