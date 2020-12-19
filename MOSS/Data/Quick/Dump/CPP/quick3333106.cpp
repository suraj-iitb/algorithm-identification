#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define INF 1e9

typedef struct{
  char suit;
  int num;
  
}Card;

int partition(Card [], int, int);
void quicksort(Card [], int, int);
void mergesort(Card [], int, int);
void merge(Card [], int, int, int);
void Compare_and_Print(Card [], Card [], int);

Card Left[MAX/2+2];
Card Right[MAX/2+2];

int main()
{
  int i;
  int n;
  char str[15];
  Card A[MAX]={};
  Card B[MAX]={};
  
  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%s%d", str, &A[i].num);
    A[i].suit = str[0];
    //A[i].suit = s;
    //A[i].num = atoi(str);
    //printf("A(suit, num) = (%c,%d)\n",A[i].suit, A[i].num);
    B[i] = A[i];
    //printf("B(suit, num) = (%c,%d)\n",B[i].suit, B[i].num);
  }
  
  quicksort(A, 0, n-1);
  mergesort(B, 0, n);

  Compare_and_Print(A, B, n);
  
  return 0;
}

void merge(Card A[], int l, int mid, int r)
{
  int i,k;
  
  int n1 = mid - l;
  int n2 = r - mid;

  for(i = 0;i < n1;i++) Left[i] = A[l+i];
  for(i = 0;i < n2;i++) Right[i] = A[mid+i];
  Left[n1].num = Right[n2].num = INF;

  int ii=0,jj=0;
  for(k = l;k < r;k++){
    if(Left[ii].num <= Right[jj].num) A[k] = Left[ii++];
    else A[k] = Right[jj++];
  }
}

void mergesort(Card A[], int left, int right)
{
  if( left+1 < right ){
    int mid = (right + left)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void quicksort(Card A[], int p, int r)
{
  int q;
  if( p < r ){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partition(Card A[], int p, int r)
{
  int i,j;
  int x;
  Card temp;
  
  x = A[r].num;
  i = p-1;
  for(j = p; j < r;j++){
    if(A[j].num <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  
  return i+1;
}

void Compare_and_Print(Card A[], Card B[], int n)
{
  int i;
  int judge = 1;

  for(i=0;i < n;i++){
    if(A[i].suit != B[i].suit){
      judge = 0;
    }
  }
  if(judge == 1) printf("Stable\n");
  else printf("Not stable\n");
  
  for(i = 0;i < n;i++){
    printf("%c %d\n",A[i].suit, A[i].num);
  }
}

