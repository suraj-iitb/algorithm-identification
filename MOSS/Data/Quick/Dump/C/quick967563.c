#include <stdio.h>
#include <stdlib.h>

typedef struct Card{
  char suit;
  int value;
  int check;
}Card;


void QuickSort(Card*,int,int);
int Partition(Card*,int,int);

main(){
  int i,n,count=0;
  Card *A;
  char c;
  scanf("%d%c",&n,&c);

  A=(Card *)malloc(sizeof(Card)*(n));
  
  for(i=0;i<n;i++){
    scanf("%c%d%c",&A[i].suit,&A[i].value,&c);
    A[i].check=i;
  }

  QuickSort(A,0,n-1);
  
  for(i=0;i<n-1;i++){
    if(A[i].value==A[i+1].value && A[i].check>A[i+1].check)count=1;
  }

  if(count==0)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].suit,A[i].value);
      }
  return 0;
}

void QuickSort(Card *A,int p,int r){
  int q;

  if(p<r){
    q=Partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
  }
}

int Partition(Card *A,int p,int r){
  int x,i,j;
  Card temp;
  x=A[r].value;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x){
      i++;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;
  return i+1;
}
