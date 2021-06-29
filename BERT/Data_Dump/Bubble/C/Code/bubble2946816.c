#include<stdio.h>

int main(){

  int n,x,flag,cnt=0;
  int i,j;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    flag = 1;
    while(flag){
      flag = 0;
      for(j=n-1;j>=i;j--){
	if(A[j]<A[j-1]){
	  x = A[j];
	  A[j] = A[j-1];
	  A[j-1] = x;
	  flag=1;
	  cnt++;
	}
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

