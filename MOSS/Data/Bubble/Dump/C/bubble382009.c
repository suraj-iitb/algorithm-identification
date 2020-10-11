/* Bubble Sort */
#include<stdio.h>
main(){
  int A[101];
  int n,i,j,temp,times=0;

  scanf("%d",&n); /* This n is length of array.*/
  if(n<1||n>100)return 0; /* Constraints: 1<= n <=100 */

  for(i=1;i<=n;i++){ 
    scanf("%d",&A[i]);
  }
  /* Bubble Sort */
  for(i=1;i<=n;i++){
    for(j=n;j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	times++;  /* This times is number of swap operations. */
      }
    }
  }
  
  for(i=1;i<n;i++){
    printf("%d ",A[i]); 
  }
  printf("%d\n",A[i]);
  printf("%d\n",times);
  return 0;
}
