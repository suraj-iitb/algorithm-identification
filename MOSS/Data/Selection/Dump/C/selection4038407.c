#include<stdio.h>

int main(){
  int n,A[101];
  int i,j,cnt=0,minj,a;

  scanf("%d",&n);

  if (n>=1 && n<=100){
    for (i=0; i<n; i++) scanf("%d",&A[i]);
    
    for (i=0; i<n; i++){
      minj = i;
      for (j=i; j<n; j++){
	if (A[j] < A[minj]){
	  minj = j;
	}
      }
      if (minj != i){
	a = A[i];
	A[i] = A[minj];
	A[minj] = a;
	cnt++;
      }
    }
    for (i=0; i<n-1; i++) printf("%d ",A[i]);
    printf("%d\n",A[i]);
    printf("%d\n",cnt);
  }

  return 0;
}

