#include<stdio.h>
#define N 100000

typedef struct Card{
  char mark;
  int numver;
  int order;
}Card;

int Partition(Card A[], int p, int r){
  int x,i,j;
  Card k;
  
  x = A[r].numver;
  i = p-1;
  for(j = p; j <= r-1; j ++){
    if (A[j].numver <= x){
      i = i+1;
      k = A[i]; 
      A[i] = A[j] ;
      A[j] = k;
    }
  }
  k = A[i+1];
  A[i + 1] = A[r];
  A[r] = k;

  return i+1;
}

void Quicksort(Card A[], int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}

int main(){
  Card A[N];
  int n, i,judge=0;
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i ++){
    scanf(" %c %d", &A[i].mark, &A[i].numver);
    A[i].order = i;
  }
  Quicksort(A, 0, n-1);
  
  for(i = 0; i < n-1; i ++){
    if(A[i].numver == A[i+1].numver){
      if(A[i].order > A[i+1].order){
	judge = 1;
	break;
      }
    }
  }
  if(judge == 0){
    printf("Stable\n");
  }
  else 
    printf("Not stable\n");
  
  for(i = 0; i < n; i ++){
    printf("%c %d\n",A[i].mark, A[i].numver);
  }
  return 0;   
}
