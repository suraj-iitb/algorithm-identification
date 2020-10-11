#include <stdio.h>

int main(){
  int num;
  int a[100];
  int i, j, swap, read;
  int count = 0;
  int min_i, min;

  scanf("%d", &num);
  for(i = 0; i < num; i++) {
    scanf("%d", &read);
    a[i] = read;
  }
  if(num == 1) printf("%d", a[0]);
  else{
  for(i = 0; i < num-1; i++){
    min_i = i; min = a[i];
    for(j = i+1; j < num; j++) if(min > a[j]){min_i = j; min = a[j];}
    if(i != min_i){
      swap = a[i];
      a[i] = a[min_i];
      a[min_i] = swap;
      count++;
    }
    printf("%d ", a[i]);
    if(i == num-2) printf("%d", a[num-1]);
  }
  }
  printf("\n%d\n", count);

  return 0;
}
