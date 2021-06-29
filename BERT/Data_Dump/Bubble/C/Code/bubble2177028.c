#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int A[N],i,j,cnt=0,temp,flag=1;
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  while(flag){
      flag = 0;
      for(j=N-1;j>0;j--){
          if(A[j] < A[j-1]){
              temp = A[j];
              A[j] = A[j-1];
              A[j-1] = temp;
              cnt++;
              flag = 1;
          }
      }
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
  return 0;
}
