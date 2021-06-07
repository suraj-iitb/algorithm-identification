#include<stdio.h>

#define N 100000
#define Q 50000

int num, renum;

int BinaryS(int *x, int *y){
  int rslt=0, left, right, mid, i;

  for(i=0; i<renum; i++){
    left = 0;
    right = num;
    
    while(left<right){
      mid = (left+right)/2;
      if(*(x+mid) == *(y+i)){
	rslt++;
	break;
      }else if(*(y+i)<*(x+mid)){
	right = mid;
      }else left = mid+1;
    }
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

  rslt = BinaryS(num1, num2);

  printf("%d\n", rslt);
  
  return 0;
  
}
