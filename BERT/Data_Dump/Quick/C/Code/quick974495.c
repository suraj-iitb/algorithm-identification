#include <stdio.h>

typedef struct c{
  char e;
  int num;
  int m;
}C;

int Partition(C *,int,int );
void QuickSort(C *,int,int );

C A[100000];

main(){
  int n,i;
  char murata;

  scanf("%d%c",&n,&murata);

  for(i = 0 ; i < n;i++ ){
    scanf("%c %d%c",&A[i].e,&A[i].num,&murata);
    A[i].m = i;
  }

  QuickSort(A,0,n - 1);

  for(i = 0 ; i < n ; i++){
    if(A[i].num == A[i+1].num && A[i].m > A[i+1].m){
      printf("Not stable\n");
      break;
    }
  }

  if(i == n){
    printf("Stable\n");
  }

  for(i = 0;i < n ;i++){
    printf("%c %d\n",A[i].e,A[i].num);
  }

  return 0;


}

int Partition(C *A, int p,int r){
  int x,i,ch,j;
  char cchh;
  x = A[r].num;
  i = p - 1;
  for(j = p ; j < r ; j++){
    if(A[j].num <= x){
      i = i + 1;
      ch = A[i].num;
      cchh = A[i].e;
      A[i].num = A[j].num;
      A[i].e = A[j].e;
      A[j].num = ch;
      A[j].e = cchh; ch = A[i].m;
      A[i].m = A[j].m;
      A[j].m = ch;
    }
  }
  ch = A[i + 1].num;
  A[i + 1].num = A[r].num;
  A[r].num = ch;

  ch = A[i + 1].m;
  A[i + 1].m = A[r].m;
  A[r].m = ch;

  cchh = A[i + 1].e;
  A[i + 1].e = A[r].e;
  A[r].e = cchh;

  return i + 1;
}

void QuickSort(C *A, int p,int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    QuickSort(A, p, q-1);
    QuickSort(A, q+1, r);
  }
}
