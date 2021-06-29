#include<stdio.h>

#define N 10000
#define Q 500

int num, renum;

int LinearS(int *x, int *y){
  int rslt=0, i, j;
  
  for(i=0; i<renum; i++)
    for(j=0; j<num; j++)
      if(*(x+j)==*(y+i)){
	rslt++;
	break;
      }


  return rslt;
}



int main (){

  int i, rslt;
  int num1[N], num2[Q];

  scanf("%d", &num);

  for(i=0; i<num; i++)
    scanf("%d", &num1[i]);

  scanf("%d", &renum);

  for(i=0; i<renum; i++)
    scanf("%d", &num2[i]);

  rslt = LinearS(num1, num2);

  printf("%d\n", rslt);
  
  return 0;
  
}
