#include<stdio.h>
#define N 100000
#define Q 50000
int main(){
  int S[N],T[Q],n,q,i,l,r,m,t=0;

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
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(T[i]==S[m]){
	t++;
	break;
      }
      else if(T[i]<S[m]){
	r=m;
      }
      else {
	l=m+1;
      }
    }
  }

  printf("%d\n",t);
  return 0;
}
