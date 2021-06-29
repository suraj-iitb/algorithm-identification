#include<stdio.h>
#define N 100001

typedef struct{
  char mark;
  int num;
  int turn;
}Card;

int Partition(Card*, int, int);
void Quicksort(Card*, int, int);
void Exchange(Card*, Card*);

main(){
  int n, i, count = 0;
  Card A[N];
  char a, B[N];
  
  scanf("%d%c", &n, &a);
  for(i = 1;i < n+1;i++){
    scanf("%c%c%d%c", &A[i].mark, &a, &A[i].num, &a);
    A[i].turn = i;
  } 
 
  Quicksort(A, 1, n);
  
  for(i = 1;i < n;i++){
    if(A[i].num == A[i+1].num && A[i].turn > A[i+1].turn){
      count++;
      break;
    }
  }
  
  if(count == 0){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  
  for(i = 1;i < n+1;i++){
    printf("%c %d\n", A[i].mark, A[i].num);
  }
  return 0;
}

int Partition(Card A[], int p, int r){
  int i, j;
  Card x;
  x = A[r];
  i = p-1;
  for(j = p;j < r;j++){
    if(A[j].num <= x.num){
      i++;
      Exchange(&A[i], &A[j]);
    }
  }
  Exchange(&A[i+1], &A[r]);
  return i+1;
}

void Quicksort(Card A[], int p, int r){
  int q, i;
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}

void Exchange(Card *a, Card *b){
  Card sub;
  sub = *a;
  *a = *b;
  *b = sub;
}
