#include<stdio.h>
#define N 100
int main(){
  int i,j,A[N],n,temp,cnt=0,minj;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj])minj=j;
    }
      	temp=A[i];
	A[i]=A[minj];
	A[minj]=temp;
	if(i!=minj)cnt++;
  }
  
  for(i=0;i<n-1;i++){
  printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],cnt);
  return 0;
}

