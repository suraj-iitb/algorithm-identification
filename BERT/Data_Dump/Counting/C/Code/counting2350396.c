#include <stdio.h>
#define N 10000

int main() {

  int i,n;
  unsigned short a[2000001],b[2000001];
  int c[N+1];
  scanf("%d",&n);
  for(i=0;i<=10000;i++) c[i] = 0;

  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    b[i+1]=0;
    c[a[i+1]]++;
  }

  for(i=1;i<=N;i++){
    c[i] = c[i] + c[i-1];
  }
  
  for(i=n;1<=i;i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }

  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");

  return 0;
}
