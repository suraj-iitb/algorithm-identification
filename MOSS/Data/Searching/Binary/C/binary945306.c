#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int n,s[N],q,t[Q],i,j,sum=0,m,l,key,r;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&t[i]);
  
  for(i=0;i<q;i++){
    l=0;
    r=n;
    key = t[i];
    while(l<r){
      m = (l+r)/2;
      if(key==s[m]){
	sum++;
	break;
      }
      if(key > s[m])l=m+1;
      else if(key < s[m])r=m;
    }
  }
  printf("%d\n",sum);
  return 0;
}
