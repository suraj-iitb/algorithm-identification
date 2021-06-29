#include <stdio.h>
#define N 100

int main(){
  int i, j;
  int num;
  int data[N];
  int temp;
  int count = 0;

  scanf("%d", &num);
  for(i = 0; i < num; i++) scanf("%d", &data[i]);

  for(i = 0; i < num; i++){
    for(j = num - 1; j >= i+1; j--){
      if(data[j] < data[j-1]){ //swap
	temp = data[j];
	data[j] = data[j-1];
	data[j-1] = temp;
	count++;
      }
    }
  }

  for(i = 0; i < num - 1; i++) printf("%d ", data[i]);
  printf("%d\n", data[i]);
  printf("%d\n", count);

  return 0;
}

