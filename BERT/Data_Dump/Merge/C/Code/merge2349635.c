#include <stdio.h>
#define MAX 500000
#define INFTY 1000000000
void margesort(int*, int , int);
void marge(int*, int, int, int);
int count = 0;

int main(){
int i, n;
int mer[MAX];

scanf("%d", &n);
for(i = 0; i<n; i++){
  scanf("%d", &mer[i]);
}

/*for(i=0; i<n-1; i++){
 printf("%d ", mer[i]);
}*/
margesort(mer ,0 , n);

for(i=0; i<n-1; i++){
 printf("%d ", mer[i]);
}
printf("%d\n", mer[n-1]);
printf("%d\n", count);

  return 0;
}

void margesort(int *A, int left, int right){
  int mid;
//  printf("left = %d\n", left);
//  printf("right = %d\n", right);
  if(left+1<right){
    mid = (left+right)/2;
  //  printf("%d\n", mid);
    margesort(A, left, mid);
    margesort(A, mid, right);
    marge(A, left, mid, right);
  }
}

void marge(int *A, int left, int mid, int right){
int i, j, k, n1, n2;
int L[MAX], R[MAX];
 n1 = mid-left;
 n2 = right-mid;


for(i = 0; i<n1; i++){
  L[i] = A[left+i];
}
for(j = 0; j<n2; j++){
  R[j] = A[mid+j];
}

L[n1] = INFTY;
R[n2] = INFTY;

i = 0;
j = 0;

for(k= left; k<right;k++){
  count++;
  if(L[i]<=R[j]){
    A[k]=L[i];
    i++;
  }
  else {
    A[k] = R[j];
    j++;
  }
}
}
