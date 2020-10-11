#include <stdio.h>

typedef struct{
  int n;
  char c;
  int status;
} Card;

void swap(Card *,Card *);
int partition(Card *,int,int);
void Quicksort(Card *,int,int);
int isStable(Card *,int);

int main(int argc, char const *argv[]) {

  int i;
  int num;
  int p = 0;
  Card A[100001];

  scanf("%d",&num);

  for( i = 0 ; i < num ; i++ ){
    scanf(" %c %d",&A[i].c,&A[i].n);
    A[i].status = i;
  }

  Quicksort(A,p,num-1);

  if( isStable(A,num) ){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }



  for( i = 0 ; i < num ; i++ ){
    printf("%c %d\n",A[i].c,A[i].n);
  }

  return 0;
}

void Quicksort(Card *A, int p, int r){

  int q;

  if( p < r ){
      q = partition(A,p,r);
      Quicksort(A,p,q-1);
      Quicksort(A,q+1,r);
  }

}



int partition(Card *A, int p, int r){

  int x;
  int i,j;

  x = A[r].n;
  i = p-1;

  for( j = p ; j < r ; j++ ){
    if( A[j].n <= x ){
      i++;
      swap(&A[i],&A[j]);
    }
  }

  swap(&A[i+1],&A[r]);

  return i+1;

}

int isStable(Card *A,int n){
  int i;
  for( i = 1 ; i < n ; i++ ){
    if( A[i-1].n == A[i].n ){
      if( A[i-1].status > A[i].status ){
        return 0;
      }
    }
  }
  return 1;
}

void swap(Card *x, Card *y){

  Card temp;

  temp = *x;
  *x = *y;
  *y = temp;

}
