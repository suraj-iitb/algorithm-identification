#include<stdio.h>

int main(){
  int n,i,minj,j,t,c=0;
  scanf("%d",&n);
  int A[n];
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
    if(A[i]!=A[minj]){
      t=A[i];
      A[i]=A[minj];
      A[minj]=t;
      c++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",c);
  return 0;
}

