#include <stdio.h>
int binarySearch(int);
int n,A[100000];
 
int main()
{
  int q,i,x,judge,num=0;
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
   
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&x);
    judge=binarySearch(x);
    if(judge) num++;
  }
   
  printf("%d\n",num);
 
  return 0;
}
 
int binarySearch(int key)
{
  int left=0;
  int right=n;
  int mid;
   
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key) return 1;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }
 
  return 0;
}
