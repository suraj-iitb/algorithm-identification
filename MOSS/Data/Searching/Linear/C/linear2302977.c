#include <stdio.h>
#define N 100000
#define Q 100000
int lineSearch(int a,int b);
int S[N];

int main(){
  int i,n,q,T[Q],a=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
   scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    a+=lineSearch(T[i],n);
  }

  printf("%d\n",a);

  return 0;
}

int lineSearch(int a,int b){
  int i=0;
  S[b]=a;
  while(S[i]!=a){
    i++;
    if(i==b)return 0;   
  }
  return 1;
}
  
