#include <stdio.h>

int n;
int A[101];

void insertionSort(void);

int main(){
  int i,j,k;

  scanf("%d",&n);

  for(i = 0;i < n; i++){
    scanf("%d",&A[i]);
  }

  for(k = 0;k < n;k++){
    printf("%d",A[k]);
    if(k == n-1)printf("\n");
    else printf(" ");
  }
  
  insertionSort();

  return 0;
}

void insertionSort(){
  int i,j,v,k;
  
  for(i = 1;i < n;i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(k = 0;k < n;k++){
      printf("%d",A[k]);
      if(k == n-1)printf("\n");
      else printf(" ");
    }
  }
}


