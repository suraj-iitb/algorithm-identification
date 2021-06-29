#include <stdio.h>

#define MAX 100

int main(){

  int i, j, v, num;
  int data[MAX];
 
  scanf("%d", &num);

  for(i = 0; i < num; i++){

    scanf("%d",&data[i]);

  }

  data[i] = -1;

  for(i = 1; i < num; i++){

    j = 0;
  
    while(data[j + 1] != -1){

      printf("%d ", data[j]);

      j++;

    }

    printf("%d\n", data[j]);


    v = data[i];
    
    j = i - 1;

    while((j >= 0) && (data[j] > v)){

      data[j + 1] = data[j];

      j--;

      data[j + 1] =v;

    }

  }

  j = 0;

  while(data[j + 1] != -1){

    printf("%d ", data[j]);

    j++;

  }

  printf("%d\n", data[j]);

  return 0;

}
