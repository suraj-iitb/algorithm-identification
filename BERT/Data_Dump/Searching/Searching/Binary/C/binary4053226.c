#include <stdio.h>

int main(){

  int n,q,i,cnt=0,a,b,c;

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

  a=0;
  c=n;
  for(i=0;i<q;i++){
    while(a<c){
      b=(a+c)/2;
      if(A[b]==B[i]){
	cnt++;
	break;
      }
      else if(B[i]<A[b]) c=b;
      else a=b+1;
    }
    a=0;
    c=n;
  }

  printf("%d\n",cnt);

    return 0;
  
}

