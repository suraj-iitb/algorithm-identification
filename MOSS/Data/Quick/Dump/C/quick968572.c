#include <stdio.h>
#define exchange(a,b) {tmp=a;a=b;b=tmp;}

typedef struct Card{
  char suit;
  int num;
  int mmm;
}Card;

int Partition(Card *A,int p,int r){
  int j;
  Card tmp;
  int x = A[r].num;
  int i = p-1;
  for (j = p;j<r;j++){
    if (A[j].num <= x){
      i = i+1;
      exchange(A[i],A[j]);  
    }
  } 
  exchange(A[i+1],A[r]);
  
  return i+1;
}

void Quicksort(Card *A, int p,int r){
  int q;
  if( p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}

int main(){
  int n,i,k;
  Card A[100000];
  char dd;
  scanf("%d%c",&n,&dd);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&A[i].suit,&A[i].num,&dd);
	A[i].mmm=i;
  }
  Quicksort(A,0,n-1);
  
  for(i=0;i<n-1;i++){
  if(A[i].num==A[i+1].num && A[i].mmm>A[i+1].mmm){
	printf("Not stable\n");i=-1;break;
  }
  }
  if(i!=-1){
  printf("Stable\n");
  }
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].suit,A[i].num);
  }  
  return 0;
  
}
