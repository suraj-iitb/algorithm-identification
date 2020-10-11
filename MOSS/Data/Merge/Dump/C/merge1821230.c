#include <stdio.h>

void margesort(int *, int, int);
void marge(int *, int, int, int);

int count = 0;
int S[5000000];
int L[2500001];
int R[2500001];

int main(){
  int n, i;

  scanf("%d", &n);
   for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  margesort(S, 0, n);
 
   for(i = 0; i < n-1; i++){
    printf("%d ", S[i]);
  }
  printf("%d\n", S[i]);
  printf("%d\n", count); 

  return 0;
}
 
void margesort(int *S, int left, int right){
  int mid;

  if(left+1 < right){ 
    mid = (left + right)/2;
    margesort(S, left, mid);
    margesort(S, mid, right);
    marge(S, left, mid, right);
  }
}

 void marge(int *S, int left, int mid, int right){
  int b1, b2;
  int i, j=0, k;
 
  b1 = mid - left;
  b2 = right - mid;
 
  for(i = 0; i < b1; i++){
    L[i] = S[left+i];
  }
  L[b1] = 1000000001;

  for(i = 0; i <b2; i++){
    R[i] = S[mid+i];
  }
  R[b2] = 1000000001;
 
  i = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){  
    S[k] = L[i];
    i++;
  }
  else{
    S[k] = R[j];
    j++;
  }
  count++;
  }
}
