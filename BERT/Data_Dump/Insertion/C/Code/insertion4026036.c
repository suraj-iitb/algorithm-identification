#include <stdio.h>
#define N 100

int main(){

  int i,j,b,v,k;
  int a[N];

  scanf("%d", &b);

  for(i = 0; i <= b-1; i++){
    scanf("%d", &a[i]);
  }
  printf("%d", a[0]);
  for(k = 1; k <= b-1; k++){
    printf(" %d", a[k]);
  }
    printf("\n");
  for(i = 1; i <= b-1; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    printf("%d", a[0]);
    for(k = 1; k <= b-1; k++){
      printf(" %d", a[k]);
    }
    printf("\n");
  }

  return 0;
}

