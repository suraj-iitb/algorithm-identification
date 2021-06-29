#include<stdio.h>
#define MAX 100000
int main(){
  int S[MAX],T[MAX];
  int i,j,cnt=0,n,q;
  int l,m,r;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    l=0;
    r=n-1;
    while(l<r){
      m=(l+r)/2;
      if(S[m]==T[i]||S[l]==T[i]||S[r]==T[i]){
	cnt++;
	break;
      }else if(S[m]<T[i]){
	l=m+1;
      }else{
	r=m;
      }
    }
  }

  printf("%d\n",cnt);

  return 0;
}
