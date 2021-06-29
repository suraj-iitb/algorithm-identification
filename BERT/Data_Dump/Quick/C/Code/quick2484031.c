#include<stdio.h>
#include<stdlib.h>

void quicksort(int, int);
int Partition(int, int);

typedef struct{
  int num;
  char mark[2];
  int order;
}card;

card A[100000];

int main(){
  int i, n, flag=0;

  scanf("%d",&n);
  if( n<1 || 100000<n ) exit(0);
  
  for( i=0 ; i<n ; i++ ){
    scanf("%s",A[i].mark);
    scanf("%d",&A[i].num);
    if( A[i].num<1 || 1000000000<A[i].num ) exit(1); 
    
    A[i].order = i;
  }
  
  quicksort(0, n-1);


  for( i=1 ; i<n ; i++ ){
    if( A[i-1].num == A[i].num){
      if(A[i-1].order > A[i].order){
      flag=1;
      break;
      }
    }
  }

  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");
  
  for( i=0 ; i<n ; i++ ){
    printf("%s %d\n",A[i].mark, A[i].num);
  }

  return 0;
}

void quicksort(int p, int r){
  int q;
  
  if(p < r){
    q = Partition(p, r);
    quicksort(p, q-1);
    quicksort(q+1, r);
  }
}

int Partition(int p, int r){
  int i, j, x, k;
  card tmp;

  x = A[r].num;
  i = p-1;

  for( j=p ; j<r ; j++ ){
    if( A[j].num <= x ){
      i++;
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
