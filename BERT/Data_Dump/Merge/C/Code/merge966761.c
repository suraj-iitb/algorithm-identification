#include<stdio.h>
#define N 500000
#define SEN 1000000000

void Merge(int, int, int);
void Merge_Sort(int, int);

int S[N], count=0;

int main(void){
  int n, i;
  
  scanf("%d", &n);
  for(i=0; i < n; i++) scanf("%d", &S[i]);
  
  Merge_Sort(0, n);
  
  for(i=0; i < n; i++){
    printf("%d", S[i]);
    if(i < n-1)printf(" ");
  }
  
  printf("\n%d\n", count);
  return 0;
}


void Merge(int left, int mid, int right){
  int n1, n2, i, j, k;
  n1 = mid-left;
  n2 = right - mid;
  int l[n1], r[n2];
  
  for(i=0; i<n1; i++) l[i] = S[left + i];
  for(i=0; i<n2; i++) r[i] = S[mid + i];
  
  l[n1] = SEN;
  r[n2] = SEN;
  i=0;
  j=0;
  
  for(k=left; k<right; k++){
    if(l[i]<=r[j]){
      S[k] = l[i];
      i++;
    }
    else{
      S[k] = r[j];
      j++;
    }
    count++;
  }
}

void Merge_Sort(int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    Merge_Sort(left, mid);
    Merge_Sort(mid, right);
    Merge(left, mid, right);
  }
}
