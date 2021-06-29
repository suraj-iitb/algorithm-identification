#include <stdio.h>
int main(){
  int N,i,j,v,k;
  scanf("%d", &N);
  int A[N];
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
   for(k=0; k<N; k++){
      printf("%d",A[k]);
      if ( k != N - 1)printf(" ");
    }
  if (i != N -1)printf("\n",N); 
  for(i=1; i<N; i++){
    v = A[i];
    j = i-1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(k=0; k<N; k++){
      printf("%d",A[k]);
      if ( k != N - 1)printf(" ");
    }
printf("\n",N);
  }
  return 0;
}
