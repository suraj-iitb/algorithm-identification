#include<stdio.h>

int main(){
  int i,j,minj,n,flag,tmp,cnt=0;
  int A[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    tmp= A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(i!=minj) cnt++;
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],cnt);
  
  return 0;
}

