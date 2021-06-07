#include <stdio.h>

#define MAX1 10000
#define MAX2 500

typedef struct kk{
  int a[MAX1];
}P;
typedef struct ll{
  int b[MAX2];
}Q;

int comp(P,int);
int n,q;

int main()
{
  int i,j = 0;
  P u;
  Q m;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&u.a[i]);
  }

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&m.b[i]);
    j += comp(u,m.b[i]);
  }
  printf("%d\n",j);
  return 0;
}

int comp(P x,int y)
{
  int i;
  for(i = 0;i < n;i++){
    if(y == x.a[i]) return 1;
  }
  return 0;
}
  

