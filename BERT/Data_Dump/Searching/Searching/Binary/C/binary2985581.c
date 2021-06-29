#include<stdio.h>
int n,q,S[100000],T[50000];
int binarysearch(int x){
int left,right,midle;
left=0;
right=n;
while(left<right){
  midle=(left+right)/2;
  if(S[midle]==x) return 1;
  else if(x<S[midle]) right=midle;
  else left=midle+1;
}

  return 0;
}
int main(){
  int i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    count+=binarysearch(T[i]);
  }
  printf("%d\n",count);

return 0;
}

