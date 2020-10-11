#include<stdio.h>
#define N 500000
#define S 1000000000
 

void Merge(int, int, int);
void Sort(int, int);
int A[N], cnt = 0;


int main(void){
  int n, i;
 
  scanf("%d", &n);
  for(i=0; i < n; i++) scanf("%d", &A[i]);

  Sort(0, n);
 
  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i < n - 1)printf(" ");
  }
 
  printf("\n%d\n", cnt);

  return 0;
}

void Merge(int left, int mid, int right){
  int i, k, j;
  int n1 = mid - left, n2 = right - mid;
  int l[n1], r[n2];
 
  for(i = 0; i < n1; i++) l[i] = A[left + i];
  for(i = 0; i < n2; i++) r[i] = A[mid + i];
 
  l[n1] = S;
  r[n2] = S;
  i = 0;
  j = 0;
 
  for(k = left; k < right; k++){
    if(l[i] <= r[j]){
      A[k] = l[i];
      i++;
    }
    else{
      A[k] = r[j];
      j++;
    }
    cnt++;
  }
}
void Sort(int left, int right){
  int mid;

  if(left + 1 < right){

    mid = (left + right) / 2;
    Sort(left, mid);
    Sort(mid, right);
    Merge(left, mid, right);
  }
}
