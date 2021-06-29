#include<stdio.h>

int main(){
  int A[100];
  int number,key,i,j,k;

  scanf("%d", &number);
  for(i = 0 ; i < number ; i ++){
    scanf("%d", &A[i]);
  }
  
  for( i = 0 ; i < number ; i ++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    
    for(k = 0 ; k < number ; k++){
      printf("%d", A[k]);
      if( k == number-1){
	printf("\n");
	break;
      }
      printf(" ");
    }
  }
  return 0;
}
