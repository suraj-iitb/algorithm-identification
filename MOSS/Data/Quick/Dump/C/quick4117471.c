#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define SENTINEL 200000000

typedef struct{
  char moji;
  int fig;
}Card;

Card L[MAX/2 + 2], R[MAX/2 + 2];

void quickSort(Card *, int, int);
void merge(Card *, int, int, int);
void mergeSort(Card *, int, int);
int partition(Card *, int, int);

int n;

int main()
{
  int i;
  int stable = 1;
  int fig;
  char s[10];
  Card A[MAX],B[MAX];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%s %d",s,&fig);
    A[i].moji = B[i].moji = s[0];
    A[i].fig = B[i].fig = fig;
  }

  mergeSort(A,0,n);
  quickSort(B,0,n-1);

  for(i = 0; i < n; i++){
    if(A[i].moji != B[i].moji)stable = 0;
  }

  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n",B[i].moji, B[i].fig);
  }
 

  return 0;
}

void merge(Card A[], int left, int mid, int right)
{
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0; i < n1; i++)L[i] = A[left + i];
  for(i = 0; i < n2; i++)R[i] = A[mid + i];
  L[n1].fig = R[n2].fig = SENTINEL;
  i = j = 0;

  for(k = left; k < right; k++){
    if(L[i].fig <= R[j].fig){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(Card A[], int left, int right)
{
  int mid;

  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int partition(Card A[], int p, int r)
{
  int i,j;
  Card t,x;

  x = A[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].fig <= x.fig){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;

  return i + 1;
}

void quickSort(Card A[], int p, int r)
{
  int q;

  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

