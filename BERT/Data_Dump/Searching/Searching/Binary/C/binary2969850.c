#include <stdio.h>

int check(int,int);

int S[100000];

int main(void){
  int n,q,key,i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(check(key,n)==1)count++;
  }
  printf("%d\n",count);
  return 0;
}

int check(int key,int n){
  int left,right,mid;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key)return 1;
    else if(S[mid]<key)left=mid+1;
    else right=mid;
  }
  return 2;
}
