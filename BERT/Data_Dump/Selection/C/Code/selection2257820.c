#include<stdio.h>
#define N 100
int main(){
  int minj, i, j, n,A[N],x,count=0,flag;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  for(i=0;i<n;i++){
    minj = i;
    flag=0;
    for(j=i;j<n;j++){
      if(A[j] < A[minj]){
	minj = j;
	flag=1;
      }
    }
    x = A[i];
    A[i] = A[minj];
    A[minj]=x;
    if(flag==1)count++;
    
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);
  
  return 0;
}
