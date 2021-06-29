#include<stdio.h>
int linearSearch(int i);

int matrix_main[10000+1];
int count_main=0;

int main(){
  int count=0;
  int input;
  int count_sub;
  int i=0,j=0;


  scanf("%d",&count_main);
  while(i != count_main){
    scanf("%d",&matrix_main[i]);
    i++;
  }
  
  scanf("%d",&count_sub);
  //  fprintf(stderr,"count_sub: %d\n",count_sub);
  for(i = 0 ; i < count_sub ; i++ ){
    scanf("%d",&input);
    //fprintf(stderr,"first_input : %d\n",input);
    if(linearSearch(input)) {
      count++;
      //fprintf(stderr,"now_count :%d input: %d\n",count,input);
    }
  }
  printf("%d\n",count);
  return 0;
}

int linearSearch(int key){
  int j=0;

  matrix_main[count_main] = key;

  while(matrix_main[j] != key){
    
    //if(j == count_main) return 0;
    j++;
  }
  return j != count_main;
}
