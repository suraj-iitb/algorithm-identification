#include<stdio.h>

int S[1000000],n;
int binarySearch(int key){
  int left=0,right=n,M;
  while(left < right){
    M = (left + right)/2;
    if(key==S[M])return 1;
    if(key>S[M])left=M+1;
    else if(key<S[M])right = M;
  }
  return 0;
}

int main(){
  int i,q,k,C=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(binarySearch(k))C++;
  }
  printf("%d\n",C);
}

