#include <stdio.h>
#define N 100

int main(void){
  
  int i,j,n,tmp,cntr=0;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cntr++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
    
  }
  printf("\n");
  printf("%d\n",cntr);
  
  return 0;
  
}
  
