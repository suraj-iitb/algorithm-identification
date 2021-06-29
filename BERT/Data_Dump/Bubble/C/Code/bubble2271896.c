#include <stdio.h>
#define N 1000
int main(){
  int n,i,j,temp,flag,count=0;
  int A[N];
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&A[i]);
  }
  flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
	flag=1;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
} 
