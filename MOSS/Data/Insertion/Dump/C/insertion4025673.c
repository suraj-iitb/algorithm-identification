#include <stdio.h>
int insertionSort();
int main(){
  int a,i,j,v,n,A[100];
  // N個の要素を含む0-オリジンの配列A
  scanf("%d",&n);
  //入力
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  //最初の並び
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d",A[n-1]);
  printf("\n");
  //そーと
  for (i = 1;i < n;i++){
    v = A[i];
    j = i - 1;
    
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    //表示
  for(a=0;a<n-1;a++)printf("%d ",A[a]);
  printf("%d",A[n-1]);
  printf("\n");
  }
  
}



