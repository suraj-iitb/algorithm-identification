#include<stdio.h>
#define MAX 100000000
int S[MAX],n;

int binarysearch(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(key==S[mid])return 1;
    if(key>S[mid])left=mid+1;
    else if(key<S[mid])right=mid;
  }
  return 0;
}

int main(){
  int q,t;
  int i,cnt=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarysearch(t))cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}