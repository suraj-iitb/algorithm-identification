#include<stdio.h>

int main(){

  int data[10000];
  int search[500];

  int i,j,sumdata,sumsearch,count;

  count = 0;

  scanf("%d",&sumdata);

  for(i = 0; i < sumdata; i++){

    scanf("%d",&data[i]);

  }

  scanf("%d",&sumsearch);

  for(i = 0; i < sumsearch; i++){

    scanf("%d",&search[i]);

  }


  for(i = 0; i < sumsearch; i++){

    for(j = 0; j < sumdata; j++){

      if(data[j] == search[i]){

	count = count + 1;
	break;

      }

    }

  }

  printf("%d\n",count);

  return 0;

}
