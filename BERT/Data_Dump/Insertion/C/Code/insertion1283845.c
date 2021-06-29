#include <stdio.h>

int main(){
  int i,n,v,j,s;
  int a[1000];

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&a[i]);
  }

  for( i=0 ; i<n ; i++ ){
    printf("%d",a[i]);
    if( i != n-1 ) printf(" ");
  }

  printf("\n");

  for( i=1 ; i<=n-1 ; i++ ){
    v = a[i];
    j = i-1;
    while( j>=0 && a[j]>v ){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    for( s=0 ; s<n ; s++ ){
      printf("%d",a[s]);
      if( s != n-1 ) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
