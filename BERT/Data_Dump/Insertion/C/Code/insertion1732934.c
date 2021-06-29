#include <stdio.h>
int main()
{
  int A[100];
  int N,i,j,v,m;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    A[j+1]=v;  
    }

    for(m=0;m<N;m++){
      if(m>0) printf(" ");
      printf("%d",A[m]);
    }
    printf("\n");
  }
  return 0;
}
