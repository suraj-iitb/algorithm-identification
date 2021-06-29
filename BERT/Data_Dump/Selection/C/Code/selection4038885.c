#include <stdio.h>

int main(){
  int i, j, n, minj, temp;
  int count=0;
  int a[100];

  scanf("%d", &n);
  for( i=0 ; i<n ; i++){
    scanf("%d", &a[i]);
  }

  for( i=0 ; i<=n-1 ; i++){
    minj = i;
    for( j=i ; j<=n-1 ; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(a[minj] != a[i]){
      count++;
    }
    temp = a[minj];
    a[minj] = a[i];
    a[i] = temp;

  }

  for( j=0 ; j<n ; j++){
    printf("%d",a[j]);
    if( j<n-1 ){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0; 
}

