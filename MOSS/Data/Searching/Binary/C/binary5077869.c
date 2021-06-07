#include <stdio.h>

int main(){
  int l,r,n,q,i,m,same=0,g;

  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  int B[n];
  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }

  for(i=0;i<q;i++){
    r=n;
    l=0;
    if(B[i]<=A[n-1] && B[i]>=A[0]){
      while(l<r){
	m=(r+l)/2;
	if(A[m]==B[i]){
	  same++;
	  break;
	}
	else if(B[i]<A[m]) r=m;
	else l=m+1;
      }
    }
  }

  printf("%d\n",same);

  return 0;
}
