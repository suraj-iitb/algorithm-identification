#include <stdio.h>
#define A 100

int i = 0;

void bubbleSort(int *, int);
void change(int *, int *);

int main(){
  int j = 0, num, bub[A];
  scanf("%d", &num);
  while(j < num){
    scanf("%d", &bub[j]);
    j++;
  }
  bubbleSort(bub, num);
  for(j=0; j<num-1; j++)
    printf("%d ",bub[j]);
  printf("%d\n",bub[j]);
  printf("%d\n", i);
  return 0;
}

void bubbleSort(int *bub, int num){
  int j = 0, k;

  while(j < num-1){
    for(k=num-1; k>=j+1; k--){
      if(bub[k] < bub[k-1]){
        i++;
        change(&bub[k], &bub[k-1]);
      }
    }
    j++;
  }
}

void change(int *small, int *big){
  int temp;
  temp = *small;
  *small = *big;
  *big = temp;
}

