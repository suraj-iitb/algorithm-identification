#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct d{
  int id;
  char mark;
  int num;
}Data;

void quicksort(Data *, int, int);
int partition(Data *, int, int);
void stableJudge(Data *, int);

int main(){
  int i, n;
  Data *A;

  scanf("%d ",&n);
  A = (Data *)malloc(sizeof(Data) * n);
  for(i=0; i<n; i++){
    scanf("%c %d ", &A[i].mark, &A[i].num);
    A[i].id = i;
  }

  quicksort(A, 0, n);

  stableJudge(A, n);

  for(i=0; i<n; i++){
    printf("%c %d\n", A[i].mark, A[i].num);
  }

  return 0;
}

void quicksort(Data *A, int p, int r){
  int i,q;
  if(p < r){
    q = partition(A, p, r);
    
    quicksort(A, p, q);
    quicksort(A, q+1, r);
  }
}

int partition(Data *A, int p, int r){
  int i=p-1, j,  x=A[r-1].num;
  Data temp;

  for(j=p; j<r-1; j++){
    if(A[j].num <= x){
      i ++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r-1];
  A[r-1] = temp;

  return i+1;
}

void stableJudge(Data *A, int n){
  int i;

  for(i=1; i<n; i++){
    if(A[i-1].num == A[i].num){
      if(A[i-1].id > A[i].id){
        puts("Not stable");
        return;
      }
    }
  }
  puts("Stable");
}

