#include<stdio.h>
#define N 100000

typedef struct {
  char m;
  int n;
} Card;

Card A[N];
Card B[N];

int Partition(Card A[], int p, int r){
  int x, i, j; 
  Card temp;
  x = A[r].n;
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].n <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }  
  temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;
  return i + 1;
}
void QuickSort(Card A[], int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}

void Merge(Card B[],int left, int mid, int right){
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  Card L[n1 + 1], R[n2 + 1];
  int i, j, k;
  for(i = 0; i < n1; i++){
    L[i] = B[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = B[mid + i];
  }
  L[n1].n = N;
  R[n2].n = N;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i].n <= R[j].n){
      B[k] = L[i];
      i++;
    } else {
      B[k] = R[j];
      j++;
    }
  }
}

void MergeSort(Card B[], int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    MergeSort(B, left, mid);
    MergeSort(B, mid, right);
    Merge(B, left, mid, right);
  }
}


int judge(int n){
  int i, j;
for(i = 0; i < n; i++){
  if(A[i].m != B[i].m) return 1;
 }
 return 0;
}

int main(){
  int n, i;
  char g;
  scanf("%d%c", &n, &g);
  for(i = 0; i < n; i++){
    scanf("%c%d%c", &A[i].m, &A[i].n, &g);
    B[i] = A[i];
  }
  QuickSort(A, 0 ,i - 1);
  MergeSort(B, 0, n);
  if(judge(n) == 0) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++) printf("%c %d\n", A[i].m, A[i].n);
  return 0;

}
