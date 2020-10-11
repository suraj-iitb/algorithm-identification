#include<stdio.h>
#define MAX 1000000
#define SENTI 2000000000

typedef struct Card{
  char pic;
  int num;
}Card;

Card L[MAX / 2 + 2];
Card R[MAX/ 2 + 2];

void Merge(Card *, int, int, int, int);
void MergeSort(Card *, int, int, int);
int Prtition(Card *, int, int, int);
void QuickSort(Card *, int, int, int);

int main(){
  int n, i, value;
  int stable = 1;
  char P[10];
  Card A[MAX], B[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%s %d",P,&value);
    A[i].pic = B[i].pic = P[0];
    A[i].num = B[i].num = value;
  }

  MergeSort(A,n,0,n);
  QuickSort(B,n,0,n-1);

  for(i = 0 ; i < n ; i++){
    if(A[i].pic != B[i].pic) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i < n ; i++){
    printf("%c %d\n",B[i].pic,B[i].num);
  }
  return 0;
}

void Merge(Card A[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;
  for(i = 0 ; i < n1 ; i++) L[i] = A[left + i];
  for(i = 0 ; i < n2 ; i++) R[i] = A[mid + i];
  L[n1].num = R[n2].num = SENTI;

  i = 0;
  j = 0;
  for(k = left ; k < right ; k++){
    if(L[i].num <= R[j].num) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void MergeSort(Card A[], int n, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    MergeSort(A, n, left, mid);
    MergeSort(A, n, mid, right);
    Merge(A, n, left, mid, right);
  }
}

int Partition(Card A[], int n, int p, int right){
  int i, j;
	Card x, tmp;

  x = A[right];
  i = p - 1;
  for(j = p ; j < right ; j++){
    if(A[j].num <= x.num){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i + 1];
  A[i + 1] = A[right];
  A[right] = tmp;
  return i+1;
}

void QuickSort(Card A[], int n, int p, int r){
  int x;

  if(p < r){
    x = Partition(A, n, p, r);
    QuickSort(A, n, p, x - 1);
    QuickSort(A, n, x + 1, r);
  }
}

