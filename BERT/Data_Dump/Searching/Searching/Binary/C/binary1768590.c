#include <stdio.h>
#define N 100000
#define Q 50000
int S[N],T[Q],n,l,r,m;
int main(){
  int i,q,Sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    if(Binary(T[i]))
      Sum++; 
  }    
  printf("%d\n",Sum);
  return 0;
}
int Binary(int key){
 int l=0;
 int r=n;

  while(l<r){
    m=(l+r)/2;
    if(key==S[m])
      return 1;
    else if(key<S[m])r=m;
    else if(key>S[m])l=m+1;
  }
  return 0;
}
