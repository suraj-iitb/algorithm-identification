#include <stdio.h>
int s[100000],n;
int binarysearch(int );
int main(){
  int i,j,k,c=0,q=0,t;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&t);
    if(binarysearch(t))c++;
  }
  printf("%d\n",c);
  return 0;
}
int binarysearch(int key)
{
  int l = 0,r = n,mid;
  while(l < r){
    mid = (l + r)/2;
    if(s[mid]==key)return 1;
    else if (key < s[mid])r = mid;
    else l=mid+1; 
  }
  return 0;
}
