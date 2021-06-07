#include<stdio.h>

#define N1 100000
#define N2 50000

int main(){
  int S[N1+1];
  int T[N2+1];
  int n,q,i,j,left,right,mid,key;
  int count=0;
  
  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &S[i]);
  scanf("%d", &q);
  for( i = 0; i < q; i++ ) scanf("%d", &T[i]);

  for(i=0;i<q;i++){
    key=T[i];
    left=0;
    right=n;

    while(left<right){
      mid=(left+right)/2;

      if(key==S[mid]){
	count++;
	break;
      }

      if(key>S[mid]){
	left=mid+1;
      }

      if(key<S[mid]){
	right=mid;
      }

    }
  }
  
  printf("%d\n",count);
  return 0;
}
