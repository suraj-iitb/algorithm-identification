#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j = 0,n,m,*A,*B,count = 0;
  
  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int));
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&m);
  B = (int *)malloc(m * sizeof(int));
  for(i = 0;i < m;i++){
    scanf("%d",&B[i]);
  }
  
  for(j = 0;j < m;j++){
    for(i = 0;i < n;i++){
      if(A[i] == B[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);
  

  return 0;
}

