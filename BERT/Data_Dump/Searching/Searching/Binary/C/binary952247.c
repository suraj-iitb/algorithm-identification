#include <stdio.h>

#define N 100000
#define Q 50000

main(){
  int n,q;
  int i,l,r,m;
  int S[N],T[Q];
  int count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    l=0;
    r=n; //両端に初期化?
    while(l<r){
      m=(l+r)/2;

      if(S[m]==T[i]){
	count++;
	break;
      }
      else if(S[m]<T[i]){
	l=m+1;
      }
      else{
	r=m;
      }
    }
  }

    printf("%d\n",count);
    return 0;
}
