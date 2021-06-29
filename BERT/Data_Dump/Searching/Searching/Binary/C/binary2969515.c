#include<stdio.h>

#define N 100000
#define Q 50000

int main(){
  int S[N];
  int T[Q];
  int i,j,k=0,n,q,count=0;
  int l,m,r;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    r=n;
    l=0;
    while(l<r){
      m=(l+r)/2;

      if(S[m]>T[i]){
	r=m;
	continue;
      }
      
      else if(S[m]<T[i]){
	l=m+1;
	continue;
      }

      else{
	count++;
	break;
      }
    }
  }
 
  printf("%d\n",count);
  
  return 0;
}

