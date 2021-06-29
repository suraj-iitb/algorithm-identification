#include <stdio.h>
int main(){  
  int n,i,j,count=0,s,k;
  scanf("%d", &n);
  int A[n];
  
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  for (i = 0;i < n-1; i++){
    for (j = n - 1; j > i; j--){
      if (A[j - 1] > A[j]){
	  s = A[j];
	  A[j] = A[j - 1];
	  A[j - 1] = s;
	  count++;
	}
      }
    }
  
     for(k=0; k<n; k++){
      printf("%d",A[k]);
      if ( k != n - 1)printf(" ");
    }
     printf("\n%d\n",count);
     return 0;
}
