#include <stdio.h>
int binarySearch(int,int,int);

int num[100000];
int main()
{
  int n,q,x,i,j;
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&num[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&x);
    if(binarySearch(0,n,x)) cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int l,int r,int q){
  int m=(l+r)/2;
  if(num[m]==q) return 1;
  else if(l==m || r==m) return 0;
  else if(num[m] < q) return binarySearch(m,r,q);
  else return binarySearch(l,m,q);
}

