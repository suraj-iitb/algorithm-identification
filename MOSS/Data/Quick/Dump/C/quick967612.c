#include<stdio.h>
#define LEN 100010
#define STABLE 1
#define NOTSTABLE 0

typedef struct{
  char c;
  int n;
}Card;

void quicksort(Card *A, int p, int r){
  int q;
  if(p<r){
    q = partion(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partion(Card *A, int p, int r){
  int x = A[r].n;
  int i = p-1;
  int j, n;
  Card k;
  
  for(j=p; j<=r-1; j++){
    if(A[j].n<=x){
      i++;
      k=A[i];
      A[i]=A[j];
      A[j]=k;
    }
  }
  
  k=A[i+1];
  A[i+1]=A[r];
  A[r]=k;
  return i+1;
}


void merge(Card *S, int left, int mid, int right){
  int i, j, k;
  int n1=mid-left;
  int n2=right-mid;
  Card L[LEN], R[LEN];
  
  for(i=0; i<n1; i++)L[i]=S[left+i];
  for(i=0; i<n2; i++)R[i]=S[mid+i];

  L[n1].n=1000000001;
  R[n2].n=1000000001;
  i=0;
  j=0;
  for(k=left; k<right; k++){
    if(L[i].n<=R[j].n){
      S[k]=L[i];
      i++;
    }
    else{
	S[k]=R[j];
	j++;
    }
  }
}

void merge_sort(Card *S, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    merge_sort(S, left, mid);
    merge_sort(S, mid, right);
    merge(S, left, mid, right);
  }
}

int main(){
  int n;
  Card A[LEN], M[LEN], card;
  int p, r; 
  int flag=STABLE;
  int i, j, k;
  char c;
  
  scanf("%d", &n);
  scanf("%c", &c);
  for(i=0; i<n; i++){
    scanf("%c %d", &A[i].c, &A[i].n);
    scanf("%c", &c);
    M[i]=A[i];
  }
  
  merge_sort(&M[0], 0, n);
  p=0;
  r=n-1;
  quicksort(&A[0], p, r);
  
  for(i=0; i<n-1; i++){
    if(A[i].c!=M[i].c){
      flag=NOTSTABLE;
      break;
    }
  }
  
  if(flag==STABLE)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++)printf("%c %d\n", A[i].c, A[i].n);
  
  return 0;
}
