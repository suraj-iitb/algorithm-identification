#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
  char gara;
  int value;
  int position;
}card;

void QuickSort(int,int);
int partition(int,int);
int inStable();

int n;
card A[100000];

int main(){

  int i;

  scanf("%d",&n);
  for(i = 1;i <= n;i++){
    scanf(" %c%d",&A[i].gara,&A[i].value);
    A[i].position = i;
  }

  QuickSort(1,n);

  if(inStable()==1)printf("Stable\n");
     else printf("Not stable\n");
  
  for(i = 1;i <= n;i++){
    printf("%c %d\n",A[i].gara,A[i].value);
   
  }
  return 0;
}

void QuickSort(p,r){
  int q;

  if(p < r){
    q = partition(p,r);
    QuickSort(p,q-1);
    QuickSort(q+1,r);
  }
}

int partition(int p,int r){

  int x;
  card y;
  int i,j;

  x = A[r].value;
  i = p-1;

  for(j = p;j <= r-1;j++){
    if(A[j].value <= x){
      i = i+1;
      y = A[i];
      A[i] = A[j];
      A[j] = y;
    }
  }
  y = A[i+1];
  A[i+1] = A[r];
  A[r] = y;
  return i+1;
}

int inStable()
{
  int i,j;

  for(i = 1;i <= n;i++){
  
    if(A[i].value == A[i-1].value){
      if(A[i].position < A[i-1].position) return 0;
    }
  }
  return 1;
}
