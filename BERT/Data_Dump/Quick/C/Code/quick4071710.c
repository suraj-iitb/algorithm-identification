#include <stdio.h>
#include <stdlib.h>
#define N 100000

typedef struct {
  char suit;
  int num;
}CARD;

void quicksort(CARD *,int,int);
int partition(CARD *,int,int);
void merge(CARD *,int,int,int);
void mergeSort(CARD *,int,int);

int main()
{
  int n,i,num,flag=0;
  char suit;
  CARD *A,*B;

  scanf("%d",&n);
  if(n<1 || n>N) exit(1);
  
  A = (CARD *)malloc(sizeof(CARD)*n);
  B = (CARD *)malloc(sizeof(CARD)*n);
  
  for(i=0;i<n;i++){
    scanf(" %c %d",&suit,&num);
    if(num<1 || num>1000000000) exit(2);
    A[i].suit = suit;
    B[i].suit = suit;
    A[i].num = num;
    B[i].num = num; //mergesortとquicksort用に2つつくる
  }

  mergeSort(A,0,n);
  quicksort(B,0,n-1);

  /*for(i=0;i<n;i++)
    printf("%c,%c\n",A[i].suit,B[i].suit);*/

  for(i=0;i<n;i++){
    if(A[i].suit != B[i].suit) flag = 1; //mergesortは常に安定だから比較すれば安定かわかる
    //printf("%c,%c\n",A[i].suit,B[i].suit);
  }
  
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++)
    printf("%c %d\n",B[i].suit,B[i].num);

  /*printf("mergesort:\n");
    for(i=0;i<n;i++)
    printf("%c %d\n",A[i].suit,A[i].num);*/
  
  
  return 0;
}

void quicksort(CARD *A,int p,int r)
{
  int q;
  
  if(p<r){
    q = partition(A,p,r);
    //printf("%d\n",q);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }

}

int partition(CARD *A,int p,int r)
{
  int i,j;
  CARD x,tmp;
  
  x = A[r];
  i = p-1;

  for(j=p;j<r;j++){
    if(A[j].num <= x.num){
      i += 1;
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

void merge(CARD *S,int l,int m,int r)
{
  int n1,n2,i,j=0,k=0;
  CARD L[N],R[N];

  n1 = m-l;
  n2 = r-m;

  //printf("確認 n1:%d , n2:%d\n",n1,n2);

  for(i=0;i<n1;i++) L[i] = S[l+i];
  for(i=0;i<n2;i++) R[i] = S[m+i];
  L[n1].num = 999999999;
  R[n2].num = 999999999;

  for(i=l;i<r;i++){
    if(L[j].num<=R[k].num){
      S[i] = L[j];
      j += 1;
    }
    else{
      S[i] = R[k];
      k += 1;
    }
  }
}
void mergeSort(CARD *S,int l,int r)
{
  int m;
  
  if(l+1 < r){
    m = (l+r)/2;
    mergeSort(S,l,m);
    mergeSort(S,m,r);
    merge(S,l,m,r);
  }
}

