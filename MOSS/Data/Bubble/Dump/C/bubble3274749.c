#include <stdio.h>
int main(){
  int N,A[100],i,j,a,count;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        a = A[j];
        A[j] = A[j-1];
        A[j-1] = a;
        count++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i==0) printf("%d",A[i]);
    else printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
