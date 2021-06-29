#include <stdio.h>
#define NOT_FOUND -1

int binarySearch(int *,int );

int n,q;

int main(){
  int i,x=0,z;
  int s[100000],t[50000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
 
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    z = binarySearch(s,t[i]);
    if(z != NOT_FOUND) x++;
  }

  printf("%d\n",x);
  
  return 0;
}

int binarySearch(int *s,int t)
{
  int left,right,mid;
  
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == t) return mid;
    else if(t < s[mid]) right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}
