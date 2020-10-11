#include <stdio.h>

int main(){
  int n,A[101];
  int i,j,k=0,flag,a,cnt=0;

  scanf("%d",&n);

  if (n>=1 && n<=100){
    for (i=0; i<n; i++) scanf("%d",&A[i]);
    flag = 1;
    while(flag){
      flag = 0;
      for (j=n-1; j>0; j--){
	if (A[j] < A[j-1]){
	  a = A[j-1];
	  A[j-1] = A[j];
	  A[j] = a;
	  flag = 1;
	  cnt++;
	}
      }
    }
    for (i=0; i<n-1; i++) printf("%d ",A[i]);
    printf("%d\n",A[i]);
    printf("%d\n",cnt);
  }
  
  return 0;
}

