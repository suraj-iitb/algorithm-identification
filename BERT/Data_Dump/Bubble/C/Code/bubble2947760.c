#include<stdio.h>
void swap(int *,int *);

int main(){
  int N;
  int A[100];
  int flag;
  int i,j,count=0;

scanf("%d",&N);
for(i=0;i<N;i++){
  scanf("%d",&A[i]);
}
flag = 1;
while(flag){
  flag = 0;
  for(j=N-1;j>=1;j--){
    if(A[j]<A[j-1]){
      swap(&A[j],&A[j-1]);
      flag=1;
      count++;
    }
  }
}
for(j=0;j<N-1;j++){
printf("%d ",A[j]);
}
printf("%d\n",A[N-1]);
printf("%d\n",count);
  return 0;
}
void swap(int *x,int *y){
  int m;
  m = *x;
  *x=*y;
  *y = m;
}

