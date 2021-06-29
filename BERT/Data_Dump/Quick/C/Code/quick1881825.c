#include <stdio.h>
#include <limits.h>

#define MAX 2000000000

typedef struct{
  int x;
  char c;
}card;

card M[100000];

int Partition(int, int);
void Quicksort(int, int);
void merge(int, int, int,card[]);
void mergeSort(int, int, card[]);

int main(){
  int i, p, n;
  char c;
  card N[100000];

  scanf("%d%c", &n, &c);

  for(i = 0; i < n; i++){
    scanf("%c%d%c", &N[i].c, &N[i].x, &c);
    M[i] = N[i];
  }

  p = 0;
  mergeSort(0, n, N);
  Quicksort(0, n-1);

  for(i = 0; i < n; i++){
    if(N[i].c != M[i].c){
      printf("Not stable\n");
      break;
    }
    if(i == (n - 1))
      printf("Stable\n");
  }
  
  for(i = 0; i < n; i++){
    printf("%c %d\n", M[i].c, M[i].x);
    }
  
  return 0;
}

int Partition(int e, int s){
  card tmp;
  int i, j, x;
  x = M[s].x;
  i = e - 1;

  for(j = e; j < s; j++){
    if (M[j].x <= x){
      i++;
      tmp = M[i];
      M[i] = M[j];
      M[j] = tmp;
    } 
  }
  tmp = M[i + 1];
  M[i + 1] = M[s];
  M[s] = tmp;
  return (i + 1);
}
  
void Quicksort(int e, int s){
  int w;
  if(e < s){
     w = Partition(e, s);
     Quicksort(e, w-1);
     Quicksort(w+1, s);
  }
}
  
void merge(int left, int mid, int right, card K[]){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  card L[100001], R[100001];

  for(i = 0; i < n1; i++){
    L[i] = K[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = K[mid+i];
  }
  L[n1].x = MAX;
  R[n2].x = MAX;

  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i].x <= R[j].x)
      K[k]=L[i++];
    else
      K[k]=R[j++];
  }
}
 
void mergeSort(int left, int right, card K[]){
  if((left + 1) < right){
    int mid = (left + right) / 2;
    mergeSort(left, mid, K);
    mergeSort(mid, right, K);
    merge(left, mid, right, K);
  }
}
