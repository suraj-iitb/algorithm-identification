#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct{
  int num;
  char mark;
  int c;
}Card;
 
int partition(Card *A,int p,int r);
void quicksort(Card *A,int p,int r);
void change_i(Card *A,int i,int j );

int main(){
  Card a[100000];
  int n,i,flag=0;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf(" %c %d", &a[i].mark,&a[i].num);
    a[i].c=i;
  }
  
  quicksort(a,0,n-1);

  for(i=0; i<n; i++){
    if(a[i].num == a[i+1].num)
      if(a[i].c > a[i+1].c) flag=1;
  }

  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");

  for ( i = 0; i < n; i++ ){
    printf("%c %d\n",a[i].mark,a[i].num);
  }
  return 0;
}

int partition(Card *A,int p,int r){
  int x,i,j,a;  
  x = A[r].num;
  
  i = p-1;
  for (j = p; j <= r-1; j++){
    if (A[j].num <= x){
      i = i+1;
      change_i(A,i,j);
    }
  }
  change_i(A,i+1,r);

  return i+1;
}

void quicksort(Card *A,int p,int r){
  int q;
  if (p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void change_i(Card *A,int i,int j ){
  Card temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
