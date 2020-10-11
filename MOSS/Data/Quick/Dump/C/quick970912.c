#include<stdio.h>
#include<stdlib.h>
#define N 100000

typedef struct{
  char c;
  int num;
  int turn;
}Card;

Card A[N];
int n;
int Partition(Card *A,int p,int r){
  int i,j;
  Card x,exc;
  x = A[r];
  i = p - 1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i = i+1;
      exc = A[i];
      A[i]= A[j];
      A[j] = exc;
    }
  }
  exc = A[i+1];
  A[i+1]=A[r];
  A[r]= exc;
  
  return i+1;
}

void Quicksort(Card *A,int p,int r){
  int q;
  if(p<r){
    q = Partition(A,p,r);
    Quicksort(A,p,q-1);
    Quicksort(A,q+1,r);
  }
}

int main(){
  int i,part,p,r;
  char g;
  scanf("%d%c",&n,&g);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&A[i].c,&A[i].num,&g);
    A[i].turn=i;
  }
  p=0;
  r=n-1;
  Quicksort(A,p,r);
  for(i=0;i<n;i++){
    if(A[i].num==A[i+1].num && A[i].turn > A[i+1].turn){
      printf("Not stable\n");
      break;
    }
    else if(i==n-1){
      printf("Stable\n");
    }
  }  
  
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].num);
  }
  return 0;
}
