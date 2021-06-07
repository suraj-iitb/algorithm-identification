#include<stdio.h>
int Binary_Search(int,int,int*);
int main()
{
  int i,count=0;
  int n,s[100000],q,t;
  
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0; i<q; i++) {
    scanf("%d",&t);
    count += Binary_Search(t,n,s);
  }    
  
  printf("%d\n",count);

  return 0;
}

int Binary_Search(int k,int n,int s[])
{
  int left=0,right=n,mid;

  while(left < right) {
    mid = (left+right)/2;
    if(s[mid] == k) return 1;
    if(s[mid]< k) left = mid+1;
    else right = mid;
  }
  return 0;
}
