#include <stdio.h>
#define N 100

int main(){

  int temp, min;
  int n;
  int i, j, k;
  int A[N];
  int count;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);    
  }
  
  /* selection_sort */
  count=0; 
  for(i=0; i<n; i++){
    // i 番目の要素を暫定的に最小値とし添字を保存
    k=i;
    for(j=i; j<n; j++){
      // より小さい値が現れたら最小値の入れ替え
      if(A[j] < A[k]){
	k=j; // 添字を保存
      }
    }
    // このループを抜けるとk に最小値の添字が入っている
    // i 番目の要素と最小値の交換
    if (k > i)
    {
      temp = A[i]; 
      A[i] = A[k];
      A[k] = temp;
      ++count;
    }
  }
  
  for(i=0; i<n; i++){
    if(i == n - 1) printf("%d", A[i]);
    else printf("%d ", A[i]);
  }
  
  printf("\n");
  printf("%d", count);
  printf("\n");
  
  return 0;
}

