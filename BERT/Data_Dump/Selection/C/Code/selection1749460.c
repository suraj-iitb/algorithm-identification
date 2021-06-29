#include<stdio.h>

#define MAX 100

int main(){

  int i, j, num, count, temp, min;
  int data[MAX];

  count = 0;

  scanf("%d", &num);

  for(i = 0; i < num; i++){

    scanf("%d", &data[i]);

  }

  for(i = 0; i < num - 1; i++){

    min = i;

    for(j = i + 1; j < num; j++){

      if(data[min] > data[j]){
	
	min = j;
	
      }
	
    }


    if(data[i] != data[min]){

      temp = data[min];

      data[min] =  data[i];

      data[i] = temp;

      count++;

    }
     
  }

  for(i = 0; i < num - 1; i++){
    
    printf("%d ", data[i]);

  }

  printf("%d\n%d\n", data[i], count);
  
  return 0;
}
