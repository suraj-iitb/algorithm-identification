#include<stdio.h>
#include<stdlib.h>


int main(){
  int i=0,j,min,element,temp;//temp = temporary
  int nowline=0,count=0,exchangeline=0;
  int *matrix;

  scanf("%d",&element);

  matrix = malloc(sizeof(int) * element);

  
  while(i < element){
    scanf("%d",&matrix[i]);
    i++;
  }

  while( nowline != element){ //element = endline

    for( i = nowline ; i < element-1 ; i++){
      
      if( i == nowline ) min = matrix[i];//startline

      if( min > matrix[i+1]){
	min = matrix[i+1];
	exchangeline = i+1;
      }
    }
    if(exchangeline != nowline){
      temp = matrix[nowline];
      matrix[nowline] = matrix[exchangeline];
      matrix[exchangeline] = temp;
      count++;
    }
    nowline++;
    exchangeline = nowline; //lnitialization
  }

  i = 0;
  while( i < element){
    printf("%d",matrix[i]);
    if(i != element-1) printf(" ");
    i++;
}
  printf("\n");
  printf("%d\n",count);
  free(matrix);

  return 0;

}
