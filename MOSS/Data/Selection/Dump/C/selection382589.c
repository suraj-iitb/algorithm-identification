/* Selection Sort */
#include<stdio.h>
main(){
  int A[101];
  int i,j,n,temp,mini,times=0;

  scanf("%d",&n); /* This n is length of array.*/
  if(n<1||n>100)return 0; /* Constraints: 1<= n <=100 */

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  /* Selection Sort */
  for(i=1;i<=n;i++){
    mini=i;
    for(j=i;j<=n;j++){
      if(A[j]<A[mini])mini=j;
    }
    temp=A[i];
    A[i]=A[mini];
    A[mini]=temp;
    if(mini!=i)times++; /* This times is number of swap operations. */
  }
  for(i=1;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",times);
  return 0;
}
