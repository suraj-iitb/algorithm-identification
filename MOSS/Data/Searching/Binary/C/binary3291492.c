#include<stdio.h>

int main(){
  int n,q,s[100000],t[50000],i,sum=0,l=0,m,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
    r=n;
    l=0;
    m=(r+l)/2;
    while(l<r){
      m=(l+r)/2;
      if(s[m]==t[i]){
	sum++;
	break;
      }else if(t[i]<s[m]){
	r=m;
      }else{
	l=m+1;
      }
    }
  }
  printf("%d\n",sum);
}

