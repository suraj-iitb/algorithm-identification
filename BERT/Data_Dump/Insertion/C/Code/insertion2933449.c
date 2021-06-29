#include <stdio.h>

int main()
{
  int n;
  int A[100];
  int i, j, k;
  int key;
  
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  // printf("--------------\n");
  for(i=0; i<n; i++){
      if(i == n - 1) printf("%d", A[i]);
      else printf("%d ", A[i]);
  }
  printf("\n");
  
  for(i=1; i<n; i++){
    key = A[i];
    //printf("key=%d\n", key);
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j = i-1;
    
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    
    for(k=0; k<n; k++){
      if(k == n - 1) printf("%d", A[k]);
      else printf("%d ", A[k]);
    }
    printf("\n");
  }
  return 0;
}

