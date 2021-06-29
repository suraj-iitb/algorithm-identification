#include<stdio.h>

void Sort(int A[],int n){
  int key,i,j,k;
  for(i = 1 ; i <= n-1  ; i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j] ;
	j--;
    }
    A[j+1] = key;
    for(k= 0; k < n ;k++){
      if(k > 0) printf(" ");
     printf("%d",A[k]);
    }
    printf("\n");
    }
}
int main(){
  int i,n,A[100];
  scanf("%d",&n);
  for(i = 0; i < n ;i++){
 
    scanf("%d",&A[i]);
  }
  for(i = 0; i < n ;i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  Sort(A,n);
  return 0;
}
