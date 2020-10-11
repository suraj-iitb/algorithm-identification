#include <stdio.h>

#define MAX 100000
#define INFTY 2000000000

typedef struct{
  char mark;
  int number;
}Card;

int partition(Card *,int ,int);
void quickS(Card *,int ,int);

void marge(Card *,int,int,int);
void margeSort(Card *,int,int);

Card L[MAX];
Card R[MAX];

int main(){
  int n;
  int i;
  int num;
  int flag=1;
  Card A[MAX],B[MAX];
  char S[2];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",S,&num);
    A[i].mark=S[0];
    A[i].number=num;
    B[i].mark=S[0];
    B[i].number=num;
  }

  margeSort(A,0,n);
  quickS(B,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].mark!=B[i].mark) flag=0;
  }

  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].mark,B[i].number);
  }

  return 0;
}



int partition(Card *A, int p, int r){
  Card judge;
  int i=0;
  int j=0;
  Card swap;
  judge=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].number<=judge.number){
      i++;
      swap=A[j];
      A[j]=A[i];
      A[i]=swap;
    }
  }
  swap=A[r];
  A[r]=A[i+1];
  A[i+1]=swap;
  return i+1;
}

void quickS(Card *A,int p,int r){
  int q=0;
  if(p<r){
    q=partition(A,p,r);
    quickS(A,p,q-1);
    quickS(A,q+1,r);
  }
}



void marge(Card *S,int left,int mid, int right){
  int i=0;
  int j=0;
  int n_S=0;
  int n_left=0;
  int n_right=0;
  
  n_left=mid-left;
  n_right=right-mid;
  
  for(i=0;i<n_left;i++){
    L[i]=S[left+i];
  }
  
  for(i=0;i<n_right;i++){
    R[i]=S[mid+i];
  }
  
  L[n_left].number=INFTY;
  R[n_right].number=INFTY;
  i=0;
  j=0;
  
  for(n_S=left;n_S<right;n_S++){
    if(L[i].number<=R[j].number){
      S[n_S]=L[i];
      i++;
    }
    else{
      S[n_S]=R[j];
      j++;
    }
  }
}

void margeSort(Card *S,int left,int right){
  int mid=0;
  if(left+1<right){
    mid=(left+right)/2;
    margeSort(S,left,mid);
    margeSort(S,mid,right);
    marge(S,left,mid,right);
  }
}

