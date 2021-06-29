#include <stdio.h>
int main(){
  int i,j,A[100],change,N,s,k,flag=0;
  scanf("%d",&N);
  for(i=0;i < N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i < N-1;i++){

    s=i;
    k=i;
    for(j=i+1; j < N ;j++){
      if(A[k] > A[j]){

        k =j;
}
    }
    if(s!=k){
      change=A[i];
      A[i]=A[k];
      A[k]=change;
      flag++;
    }
  }
  for(j=0;j < N ;j++){
    if(j==N-1){
      printf("%d",A[j]);
    }
    else{
      printf("%d ",A[j]);
    }
  }
  printf("\n");
  printf("%d\n",flag);
  return 0;
}

