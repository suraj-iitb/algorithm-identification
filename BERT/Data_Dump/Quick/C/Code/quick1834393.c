#include <stdio.h>
#include <stdlib.h>

int q;

typedef struct{
  char suit;
  int num;
  int index;
} card;

int part(card *a, int p, int r){
  int i, j, x;
  card tmp;

  x = a[r].num;
  i = p-1;

  for(j = p; j < r; j++){
    if(a[j].num <= x){
      i++;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;

  return i+1;
}

void quick(card *a, int p, int r){
  if(p < r){
    q = part(a, p, r);
    quick(a, p, q-1);
    quick(a, q+1, r);
  }
}

int isStable(card *in, int n){
  int i;
  for(i = 0; i < n; i++)
    if(in[i].num == in[i+1].num)
      if(in[i].index > in[i+1].index)
        return 0;
  return 1;
}

int main(){
  int i, j, q, n, isstb;

  scanf("%d", &n);
  card *a;
  a = malloc(sizeof(card) * n);

  for(i = 0; i < n; i++){
    scanf(" %c%d", &a[i].suit, &a[i].num);
    a[i].index = i;
  }

  quick(a, 0, n-1);
  isstb = isStable(a, n);

  if(isstb == 0)
    printf("Not stable\n");
  else if(isstb == 1)
    printf("Stable\n");
  else
    printf("isstb is not 1 or 0\n");
  for(i = 0; i < n; i++)
    printf("%c %d\n", a[i].suit, a[i].num);

  free(a);

  return 0;
}
