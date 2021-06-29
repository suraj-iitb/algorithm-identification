#include <stdio.h>

int main(){

  int n,i,j,count=0,tmp;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	count++;
      }
    }
  }
    for(i=0;i<n;i++){
      printf("%d",A[i]);
      if(i == n-1){
	printf("\n");
	break;
      }
      else printf(" ");
    }
    printf("%d\n",count);
    return 0;
}

