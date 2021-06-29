//挿入ソートのプログラム
//Ebitani Akira
//2018-12-04

#include <stdio.h>

#define N 100

int main(){
  int i,j,k;
  int array[N];
  int num;
  int key;

  //imput data
  scanf("%d",&num);
  for(i=0; i<num; i++){
    scanf("%d",&array[i]);
  }

  for(j=1; j<num; j++){
    key=array[j];
    i =j-1;

    for(k=0; k<num; k++){
      printf("%d",array[k]);
      if(k!=num-1)printf(" ");
    }
    printf("\n");
    

    while(i>=0 && array[i]>key){
      array[i+1]=array[i];
      i--;
    }
    array[i+1]=key;
  }
  for(k=0; k<num; k++){
    printf("%d",array[k]);
    if(k!=num-1)printf(" ");
  }
  printf("\n");

  return 0;
}
      

