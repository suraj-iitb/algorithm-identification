#include<stdio.h>

int A[100000], n;

int bS(int k);

int main(){
  int i, j, q, k, sum=0;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
  }
  
  scanf("%d", &q);
  for(j=0;j<q;j++){
    scanf("%d", &k);
    if(bS(k)) sum++;
  }
  printf("%d\n", sum);

  return 0;
}
  
  
int bS(int k){
  int l = 0;
  int r = n;
  int m;
  while(l < r){
    m=(l + r) / 2;
    if(k == A[m])return 1;
    if(k > A[m]) l = m + 1;
    else if(k < A[m]) r = m;
  }
  return 0;
}
