#include <stdio.h>

int main(){

  int n,q,i,j,cnt=0;

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
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(B[i]==A[j]){
	cnt++;
	break;
      }
    }
  }

  printf("%d\n",cnt);

  return 0;
  
}

