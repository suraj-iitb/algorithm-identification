#include <stdio.h>
int main(){
  int N,A[100],i,j,a,min,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N-1;i++){
    min = i;
    for(j=i+1;j<N;j++){
      if(A[j]<A[min]) min = j;
    }
    if(A[i]!=A[min]) count++;
      a = A[i];
      A[i] = A[min];
      A[min] = a;
  }
  for(i=0;i<N;i++){
    if(i==0) printf("%d",A[i]);
    else printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
