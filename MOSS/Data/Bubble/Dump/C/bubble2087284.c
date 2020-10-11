#include <stdio.h>

#define MAX 101


int main(){

  int n;
  scanf("%d%*c", &n);

  int a[MAX], b[MAX];
  int i,j,k;
  for(i = 0; i < n; i++){
    scanf("%d%*c", &a[i]);
  }

  int count = 0;

  int tmp;
  for(i = 0; i < n-1; i++){
    for(j = n-1; j >= 1; j--){
      if(a[j-1] > a[j]){
	tmp = a[j-1];
	a[j-1] = a[j];
	a[j] = tmp;
	count++;
      }
    }
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], count);
  
  return 0;
}
