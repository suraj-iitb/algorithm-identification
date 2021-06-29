#include <stdio.h>
int main(){
  int i,j,n,m,A[100],key;
  scanf("%d",&j);
  for(i=0 ; i<j ; i++){
    scanf("%d",&A[i]);
  }
  for(i=0 ; i<j-1 ;i++){
  printf("%d ",A[i]);
  }
  printf("%d",A[i]);
  printf("\n");
  for(n=1 ; n<j ; n++){
    key = A[n];
    m = n-1;
    while (m>=0 && A[m]>key){
      A[m+1] = A[m];
      m--;
      A[m+1] = key;
    }
    for(m=0 ; m<j-1 ; m++){
	printf("%d ",A[m]);
    }
    printf("%d",A[m]);
    printf("\n");
  }
  return 0;
}
