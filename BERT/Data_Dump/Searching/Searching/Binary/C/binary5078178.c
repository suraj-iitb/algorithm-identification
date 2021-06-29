#include<stdio.h>
int A[1000000];
int n;
int search(int door){
  int left = 0;
  int right = n;
  int midium;
  while( left < right ){
    midium = (left + right ) /2;
    if ( door == A[midium] ) return 1;
    if ( door > A[midium] ) left = midium+1;
    else if ( door < A[midium] ) right = midium;
  }
  return 0;
}
main(){
  int i, p, k, sim = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &p);
  for (i = 0; i < p; i++){
    scanf("%d", &k);
    if (search( k )) sim++;
  }
  printf("%d\n", sim);
  return 0;
}
