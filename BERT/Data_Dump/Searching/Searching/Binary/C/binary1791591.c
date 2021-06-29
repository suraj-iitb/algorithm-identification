#include<stdio.h>

int main(){

  int data[100000];
  int search[50000];

  int i,j,sumdata,sumsearch,left,right,mid,count;

  count = 0;
  left = 0;

  scanf("%d",&sumdata);

  right = sumdata;


  for(i = 0; i < sumdata; i++){

    scanf("%d",&data[i]);

  }

  scanf("%d",&sumsearch);

  for(i = 0; i < sumsearch; i++){

    scanf("%d",&search[i]);

  }



  for(i = 0; i < sumsearch; i++){

    left = 0;
    right = sumdata;


    while(left < right){

      mid = (left + right) / 2;

      if(data[mid] > search[i]){

	right = mid;

      }

      else if(data[mid] < search[i]){

	left = mid + 1;

      }

      else if(data[mid] == search[i]){

	count = count + 1;

	left = 0;
	right = sumdata;
	break;


      }

    }

  }

  printf("%d\n",count);

  return 0;

}
