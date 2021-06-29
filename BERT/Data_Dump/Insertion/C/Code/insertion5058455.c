#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,k,A[1000],n,v;
  int N[100];

  scanf("%d",&n); //*数列の長さ*//
  if(n<=0||n>100){
    printf("error\n"); //*制約以外ならerror表示*//
    exit(1);
  }

  //*数列の要素*//
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  //*数列の中身の表示*//
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");

  
  for(i=1;i<=n-1;i++){
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v){
        A[j+1]=A[j];
        j--;
      }
      A[j+1]=v;
      for(k=0;k<n-1;k++){
	printf("%d ",A[k]);
      }
      printf("%d",A[n-1]);  
      printf("\n");
  }
  return 0;
}

