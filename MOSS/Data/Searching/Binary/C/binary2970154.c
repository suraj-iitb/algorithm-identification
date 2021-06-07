#include<stdio.h>
#define N 100000

int S[N],n;

int BinarySearch(int flag){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid = (left+right)/2;
    if(flag==S[mid])return 1;
    if(flag>S[mid])left=mid+1;
    else if(flag<S[mid])right=mid;
  }
  return 0;
}

int main(){
  int i,q,flag,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&flag);
    if(BinarySearch(flag)==1)sum++;
  }
  printf("%d\n",sum);
  return 0;
}

