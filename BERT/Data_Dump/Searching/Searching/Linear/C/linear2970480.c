#include <stdio.h>

int main(){
  int i,j,n,q,count=0;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  int B[q];
  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
	if(A[i]==B[j]){
	  count++;
	  break;
	}
      }
    }
  printf("%d\n",count);
  return 0;
}

