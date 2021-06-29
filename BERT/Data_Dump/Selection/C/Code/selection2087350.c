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
  int minj;
  int tmp;
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]) minj = j;
    }

    if(minj != i){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;
    }
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], count);
  
  return 0;
}
