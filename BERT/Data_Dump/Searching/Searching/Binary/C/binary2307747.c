#include <stdio.h>
#define N 100000
#define Q 50000
int binarySearch(int*, int);
int n;
int main()
{
  int q;
  int s[N],t[Q];
  int i;
  int c=0,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t[i]);
  }

  for(i=0; i<q; i++){
    c = binarySearch(s,t[i]);
    if(c==1) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
  
}

int binarySearch(int *x,int key)
{
  int right,left,mid;
  right = n;
  left = 0;

  while(left < right){
    mid = (left + right) / 2;

    if(x[mid]==key) return 1;

    else if(key < x[mid]) right = mid;

    else left = mid + 1;

  }

  return 0;
}
