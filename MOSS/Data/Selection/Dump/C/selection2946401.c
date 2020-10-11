#include<stdio.h>
int main() {
  int n,i,j,minj,tmp,count=0,flag=0;
  int a[100];
  
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&a[i]);
  }

  for(i = 0 ; i <= n-1 ; i++) {
    minj = i;
    for(j = i ; j <= n-1 ; j++) {
      if(a[j] < a[minj]) {
	minj = j;
      }
    }
    if( minj != i) {
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;      
    }
  }
  
  for(i = 0 ; i < n-1 ; i++) {
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

