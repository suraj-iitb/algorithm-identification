#include <stdio.h>

#define A 100

void selectsort(int *, int);
void change(int *, int *);

int c = 0;

int main(){
  int len, num[A], i=0;
  scanf("%d", &len);
  while(i < len){
    scanf("%d", &num[i]);
    i++;
  }

  selectsort(num, len);

  for(i=0; i<len-1; i++)
    printf("%d ", num[i]);
  printf("%d\n", num[i]);
  printf("%d\n", c);
  return 0;
}

void selectsort(int *num, int len){
  int i, j, minj;
  for(i=0; i<=len-1; i++){
    minj = i;
    for(j=i; j<=len-1; j++){
      if(num[j] < num[minj])
        minj = j;
    }
      if(minj != i){
        change(&num[i], &num[minj]);
        c++;
      }
   }
}

void change(int *small, int *big){
  int temp;
  temp = *small;
  *small = *big;
  *big = temp;
}

