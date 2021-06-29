#include <stdio.h>

#define N 100


int main(){

  int n, i, j, A[N];
  int mini, swap, count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);


  for(i=0;i<n-1;i++){

    mini = i;

    for(j=i+1;j<n;j++)
      if(A[mini]>A[j]) mini = j;

    if(mini != i){
	swap = A[i];
	A[i] = A[mini];
	A[mini] = swap;
	count++;
    }


  }

  printf("%d",A[0]);
  for(i=1;i<n;i++) 
    printf(" %d",A[i]);
  
  printf("\n%d\n", count);

  return 0;

}
