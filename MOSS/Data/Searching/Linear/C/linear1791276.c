#include <stdio.h>

int main(){
  int num1,num2,i,j=0,count=0;
  int N1[10000];
  int N2[500];

  scanf("%d",&num1);
  for(i=0; i<num1; i++){
    scanf("%d",&N1[i]);
  }

  scanf("%d",&num2);
  for(i=0; i<num2; i++){
    scanf("%d",&N2[i]);

    while(N1[j] != N2[i]){ j++;

      if(j == num1) break;
    }
    
    if(j == num1) count+=0;
    else count++; 

    j=0;
  }

  printf("%d\n",count);
  return 0;
}
