#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Card{
	char suit;
	int value;
};

void mergeSort(struct Card *, int, int);
void quickSort(struct Card *, int, int);
struct Card *A;
struct Card *L;
struct Card *R;
struct Card *sortS;
int n;
int count=0;
struct Card *B;

int main(){
  int stable = 1;
  int q;
  int flug=0;
  int i,j;
  
  scanf("%d",&n);
  A = (struct Card *)malloc(sizeof(struct Card) * n);
  B = (struct Card *)malloc(sizeof(struct Card) * n);
  for(i=0;i<n;i++){
    scanf("%s %d",&A[i].suit,&A[i].value);
    B[i].suit = A[i].suit;
	B[i].value = A[i].value;
}
 
  mergeSort(A,0,n);
  quickSort(B,0,n-1);
	
  for(i=0; i<n; i++){
  	if(A[i].suit != B[i].suit) stable = 0;
  }

	if(stable == 1) printf("Stable\n");
	else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].suit, B[i].value);
  }
  
}

void merge(struct Card A[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
 
  n1 = mid - left;
  n2 = right - mid;
  L = (struct Card *)malloc(sizeof(struct Card)*(n1+2));
  R = (struct Card *)malloc(sizeof(struct Card)*(n2+2));
  for (i = 0;i < n1; i++){
    L[i] = A[left + i];
  }
  for (i = 0; i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1].value = 1000000001;
  R[n2].value = 1000000001;
  i = 0;
  j = 0;
  for (k = left;k<right;k++){
    count++;
    if(L[i].value <= R[j].value){
      A[k] = L[i];
      i = i + 1;
    }else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}


void mergeSort(struct Card *A,int left,int right){
  int mid;
  if(left+1<right){
    mid = (left +right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void quickSort(struct Card *A, int p, int r){
	int q;
	if(p < r){
		q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}
int partition(struct Card *A,int p,int r){
  int x;
  int i,j;
  struct Card tmp;
  x = A[r].value;
  i = p - 1;
  for(j=p; j<r; j++){
    if(A[j].value <= x ){
      i = i + 1;
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


