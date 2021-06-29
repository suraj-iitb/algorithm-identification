#include<stdio.h>
#include<math.h>


int main(void){


  int i ,j;
  int a[100] = {};
  int n;
  int count = 0;
  int tmp;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(j = 0; j < n -1; j++){
    for(i = n-1; i > j; i--){
      if(a[i] < a[i - 1]){
        tmp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tmp;
        count++;
      }
    }
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", count);

  return 0;
}


