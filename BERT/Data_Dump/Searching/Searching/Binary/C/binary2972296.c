#include<stdio.h>
#include<stdlib.h>
int binarysearch(int*,int,int);
int main(){
  int i=0,q,k,cnt=0;
  int n;
  int *t,*s;
  scanf("%d",&n);
  s=(int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  t=(int *)malloc(q * sizeof(int));
   for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
    k=binarysearch(s,t[i],n);
    if(k==1)cnt++;
  }
  printf("%d\n",cnt);
  free(t);
  free(s);
  return 0;
}
int binarysearch(int s[],int key,int n){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==key)return 1;
    else if(key<s[mid])right=mid;
    else left=mid+1;
  }
  return 0;
}

