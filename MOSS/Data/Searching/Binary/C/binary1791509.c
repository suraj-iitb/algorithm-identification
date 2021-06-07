#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int s,t,S[N],T[Q],i,l,m,r,count=0,n;

  scanf("%d",&s);
  
  for(i=0;i<s;i++)scanf("%d",&S[i]);
  
  scanf("%d",&t);
  
  for(i=0;i<t;i++)scanf("%d",&T[i]);
  
  l=0;
  r=s-1;
  
  for(i=0;i<t;i++){
    l=0;
    r=s;
    while(1){
      m=(l+r)/2;
      if(T[i]==S[m]){
	count++;
	break;
      }
      if(T[i]<S[m])r=m;
      if(S[m]<T[i])l=m+1;
      if(r==l)break;
    }
  }
  printf("%d\n",count);
  return 0; 
}
