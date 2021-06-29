#include<stdio.h>
#define N 100

int main(){
  
  int i,j,A[N],count=0,n,tmp,flag;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	count++;
	flag=1;
      }
    }
  }


  
  for(i=0;i<n;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");


  
  printf("%d\n",count);
  return 0;
}


