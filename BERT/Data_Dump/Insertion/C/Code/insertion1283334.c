#include <stdio.h>
#define A 100

int main(void){

  int n=0, i, j, v=0;
  int a[A];
  
  scanf("%d", &n);
  for(i=0;i < n; i++) scanf("%d", &a[i]);

  for(i=0;i < n; i++){
    printf("%d", a[i]);
    if(i == n-1){
      printf("\n");
      break;
    }
    printf(" ");
  }

  for(i=1; i < n; i++){
    v = a[i];
    j = i - 1;

    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    for(j=0;j < n; j++){
      printf("%d", a[j]);
      if(j == n-1){
	printf("\n");
	break;
      }
      printf(" ");
    }
  }
  return 0;
}
