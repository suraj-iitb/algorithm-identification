#include<stdio.h>
#define N 100

int main(){
  int i,n,a[N],k,j,ans;

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&a[i]);
  }

  for( i = 0 ; i < n ; i++ ){
    for( j = n-1 ; j > i ; j-- ){
      if( a[j] < a[j-1] ){
        k = a[j];
        a[j] = a[j-1];
        a[j-1] = k;
        ans++;
      }
    }
  }

  for( i = 0 ; i < n-1 ; i++ ){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[n-1],ans);

  return 0;
}

