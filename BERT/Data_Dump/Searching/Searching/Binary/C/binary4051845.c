#include <stdio.h>

#define MAX1 100000

typedef struct kk{
  int a[MAX1];
}P;


int binary(P,int);
int n;

int main()
{
  int i,j = 0,m,q;
  P u;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&u.a[i]);
  }

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&m);
    j += binary(u,m);
  }
  printf("%d\n",j);
  return 0;
}

int binary(P x,int y)
{
  int left = 0,right = n;
  int mid;
  while(left < right){
    mid = (left+right)/2;
    if(x.a[mid] == y) return 1;
    else if(y < x.a[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}
  

