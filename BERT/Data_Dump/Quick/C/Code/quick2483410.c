#include<stdio.h>

#define N 100000

typedef struct{
  char x;
  int n;
  int r;
}Card;

void quickSort(Card[],int,int);
int partition(Card[],int,int);
int isStable(Card[]);

int n;

int main(){
  int i;
  Card A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c %d",&A[i].x,&A[i].n);
    A[i].r=i;
  }

  quickSort(A,0,n-1);  

  if(isStable(A)) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].x,A[i].n);
  }

  return 0;
}

void quickSort(Card A[],int p,int r){
  int q;
  if(p<r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
  return;
}

int partition(Card A[], int p, int r){
  int x,i,j;
  Card tmp;

  x=A[r].n;

  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].n<=x){
      i = i+1;
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }

  tmp=A[i+1];
  A[i+1]=A[r];
  A[r]=tmp;

  return i+1;
}

int isStable(Card A[]){
  int i;

  for(i=0;i<n;i++){
    if( A[i].n == A[i+1].n && A[i].r > A[i+1].r ) return 0;
  }
  
  return 1;
}
