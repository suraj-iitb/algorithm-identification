#include<stdio.h>
#include<stdlib.h>
#define N 100000

typedef struct{
  char suit;
  int num;
}Card;


void quickSort(Card *,int ,int);
int partition(Card *,int ,int);
void merge(Card *,int ,int ,int);
void mergeSort(Card *,int ,int);

int main(){
  int i;
  int n,num,flag=0;
  char suit;
  Card *A,*B;

  scanf("%d",&n);
  A=(Card *)malloc(sizeof(Card)*n);
  B=(Card *)malloc(sizeof(Card)*n);

  for(i=0;i<n;i++){
    scanf(" %c %d",&suit,&num);
    A[i].suit=suit;
    B[i].suit=suit;
    A[i].num=num;
    B[i].num=num;
  }
  mergeSort(A,0,n);
  quickSort(B,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].suit != B[i].suit)flag=1;
  }
  
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
  
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].num);
  }
  return 0;
}

void merge(Card *S,int l,int m,int r){
  int i;
  int n1,n2,j=0,k=0;
  Card L[N],R[N];
  n1=m-l;
  n2=r-m;

  for(i=0;i<n1;i++)L[i]=S[l+i];
  for(i=0;i<n2;i++)R[i]=S[m+i];
  L[n1].num=R[n2].num=2000000000;

  for(i=l;i<r;i++){
    if(L[j].num<=R[k].num){
      S[i]=L[j];
      j+=1;
    }
    else{
      S[i]=R[k];
      k+=1;
    }
  }
}

void mergeSort(Card *S,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(S,l,m);
    mergeSort(S,m,r);
    merge(S,l,m,r);
  }
}
void quickSort(Card *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}
int partition(Card *A,int p,int r){
  int i,j;
  Card x,tmp;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i+=1;
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
