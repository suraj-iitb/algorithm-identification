
#include<stdio.h>
int count =0;

void output(int array[], int x){
  int i;
  for(i = 0;i < x;i++){
    if(i > 0 && i < x){
      printf(" ");
    }
    printf("%d",array[i]);
    
  }
  printf("\n%d\n",count);
}
   

 void bubble(int array[], int x ){
  int i,j,tmp;
 
  for(i = 0; i < x-1;i++){
    for(j= x-1;j > i;j--){
      if(array[j-1]>array[j]){
	count++;
	tmp = array[j];
	array[j] = array[j-1];
	array[j-1] = tmp;
      }

    }
   
  }
  }


int main(){
  int x;
 
  int i;
  int array[101];
  scanf("%d",&x);
    for(i = 0;i< x;i++){
      scanf("%d",&array[i]);
    }
  bubble(array ,x);
  output(array ,x);

  return 0;
}

