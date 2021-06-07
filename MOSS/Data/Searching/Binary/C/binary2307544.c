#include <stdio.h>
int binary(int n,int *s,int t){
  int mid,right,left;
  right = n;
  left = 0;
  mid = (right + left)/2;
  while(left != mid){
    mid = (left + right)/2;
    if(s[mid] < t) left = mid+1;
    else if(s[mid] > t) right = mid;
    else if(s[mid] == t) return 1;
  }
  return 0;
}

int main(){
  int n,q;
  int s[100000],t[50000];
  scanf("%d",&n);
  int i;
  for (i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);
  int count=0;
  for (i=0;i<q;i++){
    if(binary(n,s,t[i])) count++;
  }
  printf("%d\n",count);
  return 0;
}
