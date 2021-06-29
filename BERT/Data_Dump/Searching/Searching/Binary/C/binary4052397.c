#include <stdio.h>
#define N 100001

int binarySearch(int*,int,int);

int main(){
  int a[N],b[N],i,n1,n2,cnt = 0;

  scanf("%d",&n1);
  for(i=0;i<n1;++i) scanf(" %d",&a[i]);

  scanf(" %d",&n2);
  for(i=0;i<n2;i++)scanf(" %d",&b[i]);

  i=0;
  while(i<n2){
    cnt += binarySearch(a,n1,b[i++]);
  }
  printf("%d\n",cnt);
  return 0;
}

int binarySearch(int *g,int n1,int Snum){
  int L=0,R,M;

  R = n1;

  while(L<R){
    M = (L + R)/2;
    if(g[M] == Snum) return 1;
    else if (g[M] > Snum) R = M;

    else L = M + 1;

  }
  return 0;
}

