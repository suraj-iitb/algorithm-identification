#include<stdio.h>

	      
int main(){
  int i, left, right, mid, n, m, count = 0;
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
    left  = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(B[i] == A[mid]){
	count++;
	break;
      }
      else if(B[i] < A[mid]){
	right = mid;
      }
      else if(B[i] > A[mid]){
	left = mid + 1;
      }
      else break;
    }
  }
  printf("%d\n", count);
}

