#include<stdio.h>

int main(){
  int n,q,i,j,count=0,l,m,r;

  scanf("%d",&n);
  int S[n];
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int T[q];
  for(j=0 ; j<q ; j++){
    scanf("%d",&T[j]);
  }

for(i=0 ; i<q ; i++){
  l=0;
  r=n;

  while(l<r){
    m=(l+r)/2;
if(T[i] == S[m]){
  count++;
  break;
}
if(T[i]>S[m]){
  l = m + 1;
}
if(T[i]<S[m]){
  r = m;
}
}
}
printf("%d",count);
printf("\n");

return 0;
}

