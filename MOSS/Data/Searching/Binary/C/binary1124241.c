#include <stdio.h>

int bSearch(long *S, int n, long t) {
  int s=0,e=n;
  while (s<e) {
    int m=(s+e)/2;
    if(S[m]==t)      return(m);
    else if (S[m]>t) e=m;
    else             s=m+1;
  }
  return(-1);
}

int main(void) {
  int n,i,c=0;
  long S[100001],q;
  scanf("%d\n",&n);
  for(i=0;i<n;i++) scanf("%ld",&S[i]);
  scanf("\n"); scanf("%ld\n",&q);
  for(i=0;i<q;i++) {
    long t;
    scanf("%ld",&t);
    if (bSearch(S, n, t)>=0) c++;
  }
  printf("%d\n",c);
  return 0;
}
