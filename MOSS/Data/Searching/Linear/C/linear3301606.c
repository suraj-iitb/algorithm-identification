#include<stdio.h>

	      
int main(){
  int i, n, m, count = 0;
  scanf("%d", &n);
  int A[n];
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  int B[m];
  for(i = 0 ; i < m ; i++){
    scanf("%d", &B[i]);
  }
  i = 0;
  for(i = 0 ; i < m ; i++){
    int j;
    for(j = 0 ; j < n ; j++){
      if(A[j] == B[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n", count);
}

