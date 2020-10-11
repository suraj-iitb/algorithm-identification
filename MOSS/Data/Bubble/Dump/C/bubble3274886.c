#include <stdio.h>
#define MAX 100

int main(){
  int i,n,tmp,cnt=0,flag=1,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag = 0;
    for(i = n-1;i > 0;i--){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);
  
}

