#include <stdio.h>
int main(){
  int i,j,N,A[1000],minj,tmp,count=0,k;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

for(i=0;i<N-1;i++){
  minj = i;
  for(j=i;j<N;j++){
    if(A[j]<A[minj]){
      minj = j;
    }
  }
  if(A[i] > A[minj]){
    count++;
  }
  tmp = A[i];
  A[i] = A[minj];
  A[minj] = tmp;

}

for(k=0;k<N-1;k++){
  printf("%d ",A[k]);
}
printf("%d\n",A[N-1]);
printf("%d\n",count);
return 0;
}
