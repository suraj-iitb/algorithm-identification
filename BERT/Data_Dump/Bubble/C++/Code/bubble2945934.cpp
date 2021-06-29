#include<stdio.h>
#include<stdlib.h>

int main() {
  int i, j, printi, l, num=0, flag, temp;
  int array[100];

  scanf("%d", &l);
  for(i=0 ; i<l ; i++) {
    scanf("%d", &array[i]);
  }

  flag = 1;
  while(flag) {
    flag = 0;

    for(j=l-1 ; j>0 ; j--) {
      if(array[j] < array[j-1]) {
	temp = array[j-1];
	array[j-1] = array[j];
	array[j] = temp;

	flag = 1;
	num++;
      }
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

