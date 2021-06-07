#include<stdio.h>
int binarySearch(int);
int s[10000000],n;
int main(){
  int i,q,judge,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&judge);
    if(binarySearch(judge)) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int key){
  int l=0,r=n,mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==s[mid]) return 1;
    if(key>s[mid]) l=mid+1;
    else if(key<s[mid]) r=mid;
  }
  return 0;
}

