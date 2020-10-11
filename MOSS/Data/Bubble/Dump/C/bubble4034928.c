#include<stdio.h>


int main(){

  int A[100],n,temp,i,j,flag=1,cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  while(flag==1){
    flag=0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	cnt++;
	flag=1;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);
  return 0;
}

