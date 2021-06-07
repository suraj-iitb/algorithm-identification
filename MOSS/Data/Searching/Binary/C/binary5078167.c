#include<stdio.h>

int S[100000],n;

int binarysearch(int);

int main(){
  int q,T,i,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(binarysearch(T)){
      sum++;
    }
  }

  printf("%d\n",sum);

  return 0;
}

int binarysearch(int T){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(T==S[mid]){
      return 1;
    }
    if(T>S[mid]){
      left=mid+1;
    }
    else if(T<S[mid]){
      right=mid;
    }
  }
    return 0;
}

