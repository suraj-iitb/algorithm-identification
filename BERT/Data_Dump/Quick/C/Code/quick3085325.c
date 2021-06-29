#include<stdio.h>
#define N 100000


typedef struct Card{
  
  char mark;
  int num, index;

}Card;


int Partition( Card A[], int p, int r ){

  int i, j,n;
  Card c;

  n = A[r].num;
  i = p - 1;

  for( j = p; j < r; j++ ){
    if( A[j].num <= n){
      i++;
      c = A[i];
      A[i] = A[j];
      A[j] = c;
    }
  }

  c = A[i+1];
  A[i+1] = A[r];
  A[r] = c;

  return i+1;
}


void QuickSort( Card A[], int p, int r ){
  int q;
  if( p < r ){
    q = Partition( A, p, r );
    QuickSort( A, p, q-1 );
    QuickSort( A, q+1, r );
  }
}

int isStable( Card A[], int n ){
  int i;
  for( i = 1; i < n; i++ ){
    if( A[i-1].num == A[i].num ){
      if( A[i-1].index > A[i].index ){
    return 0;
      }
    }
  }
    return 1;
}

int main(void){
  int i, n;
  Card S[N];

  scanf("%d", &n);
  for( i = 0; i < n; i++ ){
    scanf(" %c %d", &S[i].mark, &S[i].num);
    S[i].index = i;
  }

  QuickSort( S, 0, n-1 );

  if( isStable(S, n) == 1 ){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for( i = 0; i < n; i++ ){
    printf("%c %d\n", S[i].mark, S[i].num);
  }
    return 0;
}

