#include <stdio.h>
void swap(int*,int*);
int main(){
  int i,j,flag,A[100],N,koukan;
  int k=0;
  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag){
    flag=0;
      for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
        swap(&A[j], &A[j-1]);
        flag=1;
        k++;
    }
   }
  }
  for(i=0;i<=N-1;i++){
    if(i==N-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
    }
  printf("%d\n",k);
  return 0;
}
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


