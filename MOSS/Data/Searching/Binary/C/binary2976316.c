#include<stdio.h>
int S[10000000],n;


int twosearch(int k){
  int left=0,right=n, mid;

  while(left<right){
    mid=(left+right)/2;
    if(k==S[mid])return 1;
    if(k>S[mid])left=mid+1;
    else if(k<S[mid])right=mid;
  }
  return 0;
}

int main(){
  int i,q, key, sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(twosearch(key))sum++;
  }
  printf("%d\n",sum);

  return 0;
}





