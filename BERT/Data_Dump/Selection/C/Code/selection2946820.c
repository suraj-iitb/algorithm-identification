#include<stdio.h>

int main(){

  int n,x,cnt=0;
  int i,j,minj;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }

    if(i!=minj){
      x = A[i];
      A[i] = A[minj];
      A[minj] = x;
      cnt++;
    }

  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",cnt);

  return 0;
}

