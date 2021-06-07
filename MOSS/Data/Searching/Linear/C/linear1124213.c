#include <stdio.h>

int main(void) {
  int n,i,c=0;
  long S[10001],q;
  scanf("%d\n",&n);
  for(i=0;i<n;i++) scanf("%ld",&S[i]);
  scanf("\n"); scanf("%ld\n",&q);
  for(i=0;i<q;i++) {
    long t;
    scanf("%ld",&t);
    int j=0;
    S[n]=t;
    while (S[j]!=t) j++;
    if(j<n) c++;
  }
  printf("%d\n",c);
  return 0;
}
