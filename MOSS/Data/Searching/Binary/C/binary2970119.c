#include<stdio.h>
#define N 100000

int S[N];
int binarySearch(int key, int n)
{
  int left=0,right=n,mid;
    while(left<right){
      mid = (left+right)/2;
      if(S[mid] == key) return 1;
      if(key < S[mid]) right = mid;
      else left = mid+1;
    }
    return 0;
}
int main()
{
  int i,n,m,key,count=0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);
  for(i=0; i<m; i++){
    scanf("%d",&key);
    if(binarySearch(key,n))count++;
  }
  printf("%d\n",count);
  return 0;
}
    
  

