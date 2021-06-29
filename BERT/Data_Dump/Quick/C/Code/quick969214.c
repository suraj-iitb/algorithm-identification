#include <stdio.h>
#define N 100000



typedef struct Card{
char c;
int a;
  int anna;
}Cards;

int Partition(int, int);
void Quicksort(int, int);
Cards A[N];

main()
{
  int n,i,j,f=0;
  char cc;

  scanf("%d%c",&n,&cc);
  
  for(i = 0; i < n; i++){
    scanf("%c%d%c",&A[i].c,&A[i].a,&cc);
    A[i].anna = i;
  }
  
  Quicksort(0, n-1);
  for(i = 0; i < n-1; i++){
    if(A[i].a == A[i+1].a && A[i].anna > A[i+1].anna){
      f = 1;
    }
  }
  if(f == 1){
    printf("Not stable\n");
  }
  else {
    printf("Stable\n");
  }
  for(i = 0; i < n; i++){
    printf("%c %d\n",A[i].c,A[i].a);
  }
  return 0;
}


int Partition(p, r)
{

  int i,j,x;
  Cards tmp;

  x = A[r].a;
  i = p-1;

  for(j = p; j <= r-1; j++){
    if(A[j].a <= x){
      i = i+1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;

  return i+1;

}

void Quicksort(int p, int r)
{
  int q;

  if(p < r){
    q = Partition(p, r);
    Quicksort(p, q-1);
    Quicksort(q+1, r);
  }
}
