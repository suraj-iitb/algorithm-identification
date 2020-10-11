#include<stdio.h>
#include<math.h>

typedef struct{
  char suit;
  int number;
} card;

int Partition(card A[], int p, int r){
  int j;
  int x = A[r].number;
  int i = p-1;
  card a;
  for(j = p;j < r;j++){
    if(A[j].number <= x){
      i++;
      a = A[i], A[i] = A[j], A[j] = a;
    }
  }
  a = A[i+1], A[i+1] = A[r], A[r] = a;
  return i+1;
}

void Quicksort(card A[], int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}

void merge(card A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j, k;
  card L[n1 + 1], R[n2 + 1];
  for(i = 0;i < n1;i++)
    L[i] = A[left + i];
  for(i = 0;i < n2;i++)
    R[i] = A[mid + i];
  L[n1].number = 1000000001;
  R[n2].number = 1000000001;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i].number <= R[j].number){
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(card A[], int left, int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void){
  int n, i;
  scanf("%d", &n);
  card A[n], B[n], C[n];
  for(i = 0;i < n;i++){
    scanf("\n%c %d", &A[i].suit, &A[i].number);
  }
  for(i = 0;i < n;i++)
    B[i] = A[i], C[i] = A[i];
  Quicksort(B, 0, n-1);
  mergeSort(C, 0, n);
  i = 0;
  while(B[i].suit == C[i].suit && B[i].number == C[i].number && i<n)
    i++;
  if(i == n)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i = 0;i < n;i++)
    printf("%c %d\n", B[i].suit, B[i].number);
  return 0;
}
