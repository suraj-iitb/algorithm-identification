#include<stdio.h>
#define N 100000

typedef struct Card{
  char mark;
  int num;
  int index;
}Card;

int Partition( Card A[], int p, int r ){
  int x, i, j;
  Card c;
  x = A[r].num;
  i = p - 1;
  for( j = p; j < r; j++ ){
    if( A[j].num <= x){
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

main(){
  int n, i;
  Card A[N];

  scanf("%d", &n);
  for( i = 0; i < n; i++ ){
    scanf(" %c %d", &A[i].mark, &A[i].num);
    A[i].index = i;
  }

  QuickSort( A, 0, n-1 );

  if( isStable(A, n) == 1 ){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for( i = 0; i < n; i++ ){
    printf("%c %d\n", A[i].mark, A[i].num);
  }
    return 0;
}
