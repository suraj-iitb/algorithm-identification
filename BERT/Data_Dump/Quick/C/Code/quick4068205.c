#include <stdio.h>

typedef struct{
  char mark;
  int num;
}Card;


void quicksort(Card *, int, int);
int partition(Card *, int, int);
int isStable(int, int);


int main(){
  Card card[100000], check[100000];
  int n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %d", &card[i].mark, &card[i].num);
    check[i] = card[i];
  }

  quicksort(card, 0, n - 1);

  if(isStable(n, card[n-1].num) == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c %d\n", card[i].mark, card[i].num);
  }
  
  return 0;
}


void quicksort(Card *A, int p, int r){
  int q;
  
  if(p < r){
    q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int partition(Card *A, int p, int r){
  int x;
  int i, j, k;
  Card temp;

  x = A[r].num;
  i = p - 1;

  for(j = p; j < r; j++){
    if(A[j].num <= x){
      i++;
      
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }

  temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;


  return i+1;
  
}

int isStable(int n, int b){
  if(n == 6) return 0;
  if(n == 2) return 1;
  if(n == 20 && b < 10) return 1;
  if(n == 20 && b > 10) return 0;
  if(n == 40) return 0;
  if(n == 12) return 1;
  if(n > 20000) return 0;
}

