#include <stdio.h>
int main(){  
  int n,i,j,count=0,minj=0,k,s=0,a=0;
  scanf("%d", &n);
  int A[n];
  
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for (i = 0;i < n; i++){
    minj = i;
    for (j = i; j < n; j++){
      if (A[j] < A[minj]){
	minj = j;
	}
    }
    if(minj > i){
      s = A[i];
      A[i] = A[minj];
      A[minj] = s;
      count++;
    }
    
    }
  
     for(k=0; k<n; k++){
      printf("%d",A[k]);
      if ( k != n - 1)printf(" ");
    }
     printf("\n%d\n",count);
     return 0;
}
