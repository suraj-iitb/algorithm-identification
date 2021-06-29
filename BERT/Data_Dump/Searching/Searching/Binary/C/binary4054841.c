#include<stdio.h>
#define S 100000
#define T 50000
int main(){
  int s[S],t[T],n,q,i,j=0,count=0,k,r,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
   scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
    k=t[i];
    l=0;
    r=n;
    while(1){
      m=(l+r)/2;
      if(s[m]==k){
	count++;
	break;
      }
      else if(s[m]<k){
	l=m+1;
      }
      else if(s[m]>k){
	r=m-1;
      }
      if(r<l){
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

