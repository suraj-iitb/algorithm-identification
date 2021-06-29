#include <stdio.h>

#define N 100000

typedef struct{
  char mark;
   int num;
   int check;
}Card;

int partition(Card *,int,int);
void quicksort(Card *,int,int);

int main(){

  int i;
  int n;
  int judge=0;
  Card sum[N];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
  scanf(" %c%d",&sum[i].mark,&sum[i].num);
  sum[i].check = i;
  }

  quicksort(sum,0,n-1);

  for(i=0;i<n-1;i++){
    if(sum[i].num == sum[i+1].num && sum[i].check > sum[i+1].check){
      judge = 1;
      break;
    }
  }

  if(judge==1){
    printf("Not stable\n");
  }
  else{
    printf("Stable\n");
  }
  
  for(i=0;i<n;i++){
  printf("%c %d\n",sum[i].mark,sum[i].num);
  }
  
  return 0;
}

  int partition(Card *A,int p,int r){

   int i;
   int j;
  Card x;
  Card tmp;
  
   x = A[r];
   i = p-1;
   
  for(j=p;j<=r-1;j++){
    if(A[j].num <= x.num){
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

void quicksort(Card *A,int p,int r){

  int q;
  
  if(p < r){
  q = partition(A, p, r);
  quicksort(A, p, q-1);
  quicksort(A, q+1, r);
  }
}
