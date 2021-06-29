#include<stdio.h>
#include<stdlib.h>

#define N 100
void print(int A[], int m){
  int i;
  for(i = 0; i < m; i++){
    if(i > 0 && i < m) printf(" ");
    printf("%d",A[i]);  
  }
  printf("\n");
}


main(){
  int i,n;
  int j=0;
  int v=0;
  int A[N];
  scanf("%d",&n);
  

  for (i= 0; i < n;i++) {
    scanf("%d",&A[i]);
    if(i<n-1) printf("%d ",A[i]);
    else printf("%d",A[i]);      
  }
  printf("\n");
  for (i= 1; i < n; i++){ //Sorting starts after A[0].
    v = A[i]; //A[i] records to v
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
      A[j+1] = v;
      print(A, n);
  }
  return 0;    
}
