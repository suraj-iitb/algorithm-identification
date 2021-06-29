#include<stdio.h>
#define N 100
int main(){
  int i,A[N],n,flag=1,temp,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }
  
  while(flag){

    flag = 0;
    for(i=n-1;i>0;i--){
      if(A[i]<A[i-1]){
	temp=A[i];
	A[i]=A[i-1];
	A[i-1]=temp;
	flag=1;
	cnt++;
      }
    }
  }
  
  for(i=0;i<n-1;i++){
  printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],cnt);
  return 0;
}

