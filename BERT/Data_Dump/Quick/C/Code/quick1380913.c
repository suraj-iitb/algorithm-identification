#include<stdio.h>
 
typedef struct{
  char m[2];
  int n;
  int o;
} Card;
 
int partition(Card *A, int p, int r){
  int i, j, a;
  Card x;
  a = A[r].n;
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].n <= a){
      i++;
      x = A[i];
      A[i] = A[j];
      A[j] = x;
    }
  }
  x = A[i + 1];
  A[i + 1] = A[r];
  A[r] = x;
  return i + 1;
}
 


void quickSort(Card *A, int p, int r){
  int q; 
  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}
 int main(){
  Card A[100000];
  int n2, i, j, v = 0;
 
  scanf("%d",&n2);
  for(i = 0; i < n2; i++){
    scanf("%s %d",A[i].m, &A[i].n);
    A[i].o = i + 1;
  }
  quickSort(A, 0, n2 - 1);
  for(i = 0; i < n2; i++){
    if(A[i].o > A[i + 1].o && A[i].n == A[i + 1].n){
      v++;
      break;
    }
  }
  if(v == 0) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n2; i++) printf("%s %d\n",A[i].m, A[i].n);
  return 0;
}
