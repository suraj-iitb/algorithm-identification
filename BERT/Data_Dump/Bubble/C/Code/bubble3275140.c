#include <stdio.h>

int main(){
  int n,i,j,key,flag,count=0;
  int A[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j=n-1;j>=i+1;j--){
      if(A[j-1]>A[j]){
	key = A[j-1];
	A[j-1] = A[j];
	A[j] = key;
	flag = 1;
	count++;
      }
    }
    i++;
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

