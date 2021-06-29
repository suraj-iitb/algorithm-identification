#include <stdio.h>
#define N 100

int main(){
  int i, j;
  int num;
  int data[N];
  int min, temp, count = 0;

  scanf("%d", &num);
  for(i = 0; i < num; i++) scanf("%d", &data[i]);

  for(i = 0; i < num; i++){
    min = i;
    
    for(j = i; j < num; j++){
      if(data[min] > data[j]) min = j;
    }

    if(min != i){
      temp = data[i];
      data[i] = data[min];
      data[min] = temp;
      count++;
    }
    
  }
  for(i = 0; i < num - 1; i++) printf("%d ", data[i]);
  printf("%d\n", data[i]);
  printf("%d\n", count);

  return 0;
}

