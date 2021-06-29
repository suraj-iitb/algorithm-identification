#include<stdio.h>

void bubbleSort(int,int[]);

int main(){

  int length;
  int data[100];
  int i = 0;

  scanf("%d",&length);


  for(i = 0; i < length; i++){

    scanf("%d",&data[i]);

  }

  bubbleSort(length,data);

  return 0;

}

void bubbleSort(int length, int data[]){

  int flag = 1;
  int j,change;
  int count = 0;

  
  while(flag){

    flag = 0;

    for(j = length-1; j !=0; j--){


      if(data[j] < data[j-1]){

	change = data[j-1];

	data[j-1] = data[j];

	data[j] = change;

	flag = 1;

	count = count + 1;

      }
    }
  }


  for(j = 0; j < length; j++){

    if(j != length-1){

    printf("%d ",data[j]);

  }

    else{

      printf("%d\n",data[j]);

    }

  }

  printf("%d\n",count);

}
 
