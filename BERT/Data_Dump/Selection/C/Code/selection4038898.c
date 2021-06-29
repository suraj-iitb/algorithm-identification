#include <stdio.h>

int main()
{
  int i,j,minj,x,y,cnt,N,A[100];

  scanf("%d",&N);
  for(i = 0;i < N;i++) scanf("%d",&A[i]);

  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(i != minj){
      x = A[i];
      y = A[minj];
      A[i] = y;
      A[minj] = x;
      cnt++;
    }
  }

    for(i = 0;i < N;i++){
      printf("%d",A[i]);
      if(i < N-1) printf(" ");
      else printf("\n");
    }
    printf("%d\n",cnt);

    return 0;
}

