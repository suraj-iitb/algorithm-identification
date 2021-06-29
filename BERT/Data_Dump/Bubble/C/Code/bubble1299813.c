#include<stdio.h>
#define N 100
main(){
  int n,i,j,A[N],b,c=0;
  scanf("%d",&n);  /* 並べる数字の個数 */
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]); 
  }
  for(i = 0; i < n; i++){
    for(j = n-1; i < j; j--){
      if(A[j] < A[j-1]){ 
	b = A[j];
	A[j] = A[j-1];  /* 並び換え部分 */
	A[j-1] = b;
	c++;
      }
    }
  }
  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",c);
  return 0;
}
