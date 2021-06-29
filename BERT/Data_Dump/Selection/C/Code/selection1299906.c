#include<stdio.h>
#define N 100
main(){
  int n,i,j,A[N],mini,b,c=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
    if(mini != i){
	b = A[i];
	A[i] = A[mini];
	A[mini] = b;
	c++;
    }
  }


  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
  }                                /* 表示 */
  printf("%d\n",A[n-1]);
  printf("%d\n",c);
  return 0;
}
