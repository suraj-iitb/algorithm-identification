#include <stdio.h>
#define SENTINEL 1000000000
int N[500000], L[250001], R[250001], count=0;

void Merge(left, mid, right){
  int n1, n2, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++)
    L[i] = N[left + i];
  for(i = 0; i < n2; i++)
    R[i] = N[mid + i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      N[k] = L[i];
      i = i + 1;
      count++;
    }
    else{
      N[k] = R[j];
      j = j + 1;
      count++;
    }   
  }
}

void Merge_Sort(left, right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    Merge_Sort(left, mid);
    Merge_Sort(mid, right);
    Merge(left, mid, right);
  }
}

int main(){
  int i, n;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&N[i]);

  Merge_Sort(0,n);

  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d",N[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
