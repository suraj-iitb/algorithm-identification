#include<stdio.h>

#define MAX 100

int main(){

  int i, j, num, count, temp;
  int data[MAX];

  count = 0;

  scanf("%d", &num);

  for(i = 0; i < num; i++){

    scanf("%d", &data[i]);

  }

  for(i = 0; i < num - 1; i++){

    for(j = num - 1; j > i; j--){

      if(data[j] < data[j - 1]){
	
	temp = data[j - 1];

	data[j - 1] =  data[j];

	data[j] = temp;
	
	count++;
	
      }
	
    }
     
  }

  for(i = 0; i < num - 1; i++){
    
    printf("%d ", data[i]);

  }

  printf("%d\n%d\n", data[i], count);
  
  return 0;
}
