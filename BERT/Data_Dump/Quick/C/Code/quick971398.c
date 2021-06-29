#include <stdio.h>

#define N 100000

typedef struct{
  char mark;
  int num;
}Card;

Card A[N], C[N];
int count=0;

void change(Card n, Card m){
  Card x;
  x = n;
  n = m;
  m = x;
}

int partition(Card A[], int p, int r){
  int i, j, x, n;
  Card B;
  x = A[r].num;
  i = p-1;
  for(j=p; j<r; j++){
    if(A[j].num <= x){
      i++;
      B = A[j];
      A[j] = A[i];
      A[i] = B;
    }
  }
  B = A[r];
  A[r] = A[i+1];
  A[i+1] = B;
  return i+1;
}

void quicksort(Card A[], int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void Merge(Card C[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1+1], R[n2+1];
  int i, j, k;

  for(i=0; i<n1; i++){
    L[i] = C[left + i];
  }

  for(i=0; i<n2; i++){
    R[i] = C[mid + i];
  }

  L[n1].num = R[n2].num = 1000000000;
  i = j = 0;
  for(k=left; k<right; k++){
    count++;
    if (L[i].num <= R[j].num){
      C[k] = L[i];
      i++;
    }
    else{
      C[k] = R[j];
      j++;
    }
  }
}

void MergeSort(Card C[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    MergeSort(C, left, mid);
    MergeSort(C, mid, right);
    Merge(C, left, mid, right);
  }
}

int main(){
  int i, n, j, frag=0;
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf("%s%d", &A[i].mark, &A[i].num);
    C[i] = A[i];
  }
  quicksort(A, 0, n-1);
  MergeSort(C, 0, n);
  for(i=0; i<n; i++){
    if(A[i].num == C[i].num && A[i].mark == C[i].mark)
      frag++;
  }
  if(frag == n) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++) printf("%s %d\n",&A[i].mark, A[i].num);
  return 0;
}
