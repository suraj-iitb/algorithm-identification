#include <stdio.h>
#include <stdlib.h>
#define M 2000001
#define VM 10000

int main(){

  unsigned short *a,*b;
  int d[VM+1];
  int n,i,j;

  scanf("%d",&n);

  a=malloc(sizeof(short)*n+1);
  b=malloc(sizeof(short)*n+1);

  for(i=0;i<=VM;i++)d[i]=0;

  for(j=0;j<n;j++){
    scanf("%u",&a[j+1]);
    d[a[j+1]]++;

  }
  for(i=1;i<=VM;i++)d[i]=d[i]+d[i-1];

  for(j=n;j>=1;j--){
    b[d[a[j]]]=a[j];
    d[a[j]]--;
  }

  for(i=1;i<=n;i++){
    printf("%u",b[i]);
    if(i<n)printf(" ");
  }
  printf("\n");



  return 0;
}

