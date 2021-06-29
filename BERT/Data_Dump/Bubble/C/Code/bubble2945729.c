#include<stdio.h>

int main(){
  int flag=1,tmp,n,i=0,j,cnt=0;
  scanf("%d",&n);
  int A[n];
  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
    i++;
  }
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j<n-1){
      printf(" ");
    }else{
      printf("\n");
    }
  }
  printf("%d\n",cnt);
  return 0;
}

