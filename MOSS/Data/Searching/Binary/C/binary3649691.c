#include <stdio.h>
int S[100000],n;
int search(int T){
  int l=0,r=n,m;
  while(l<r){
    m=(l+r)/2;
    if(T==S[m]) return 0;
    else if(T>=S[m]) l=m+1;
    else if(T<=S[m]) r=m;
  }
  return 1;
}

int main(){
  int q,T,i,a=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(search(T)==0) a++;
  }
  printf("%d\n",a);
  return 0;
}

