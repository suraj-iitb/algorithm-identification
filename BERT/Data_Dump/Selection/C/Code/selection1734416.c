#include<stdio.h>
#define N 100

int main()
{
  int i,j,m,count=0,minj,tmp;
  int A[N];

  scanf("%d",&m);
  for(i = 0;i < m;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0;i <=m-1;i++){
    minj = i;
    for(j = i;j <= m-1;j++){
      if(A[j] < A[minj]) {
	minj = j;   
      }
    }
    if(minj == i) continue;
    count++;

    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }

  for(i = 0;i < m-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[m-1]);
  printf("%d\n",count);

  return 0;
}
