#include<stdio.h>
#include<stdlib.h>

int binarySearch(int S[],int n,int T){
  int l=0,m;
  int r=n;
  while(l<r){
    m=(l+r)/2;
    if(S[m]==T)return 1;
    else if(T<S[m])r=m;
    else l=m+1;
  }
  return 0;
}

int main(){
  int i,c=0;
  int n,q,T;
  int *S;

  scanf("%d",&n);
  S = (int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(binarySearch(S,n,T)==1)c++;
  }
printf("%d\n",c);

return 0;
}
