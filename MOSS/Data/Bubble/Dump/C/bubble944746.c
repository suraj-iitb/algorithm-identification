#include<stdio.h>
 
int main(void){
  int len, i, j, temp, count=0;
  int N[100];
 
  scanf("%d", &len);
  for(i=0; i<len; i++){
    scanf("%d", &N[i]);
  }
   
  for(i=0; i<len; i++){
    for(j=len-1; j>i; j--){

      if(N[j] < N[j-1]){

	temp = N[j];
	N[j] = N[j-1];
	N[j-1] = temp;

	count++;
      }

    }
  }
   
  for(i=0; i<len; i++){
    if(i<len-1){
      printf("%d ", N[i]);
    }else{
      printf("%d\n", N[i]);
    }
  }
   
  printf("%d\n", count);
  return 0;
}
