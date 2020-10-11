#include<stdio.h>
#include<stdlib.h>

int main() {
  int i, j, printi, l, num=0, temp, minj;
  int array[100];

  scanf("%d", &l);
  for(i=0 ; i<l ; i++) {
    scanf("%d", &array[i]);
  }

  for(i=0 ; i<l ; i++) {
    minj = i;

    for(j = i ; j<l ; j++){
      if(array[j] < array[minj]){
	minj = j;
      }
    }

    if(i != minj) {
      temp = array[i];
      array[i] = array[minj];
      array[minj] = temp;
      num++;
    }
  }

  for(printi = 0 ; printi < l; printi++) {
    printf("%d", array[printi]);
    if(printi != l-1) printf(" ");
  }
  printf("\n");

  printf("%d\n", num);
  
  return 0;
}

