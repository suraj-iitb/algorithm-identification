#include <stdio.h>
#define N 100000

int bs(int key);

int n;
int s[N];
int main(){

  int key,count=0;
  int i,q;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(bs(key)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int bs(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(key==s[mid]) return 1;
    if(key>s[mid]) left=mid+1;
    else if(key<s[mid]) right=mid;
  }
  return 0;
}
