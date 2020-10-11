#include<stdio.h>
#include<stdlib.h>

  int main(){
  int A[100];
  int i,x,y,N;
  int z=0;
  scanf("%d",&N);
for(i=0;i<N;i++){
  scanf("%d",&A[i]);
}
for(i=0;i<N;i++){ 
for(x=N-1;x>i;x--){
  if(A[x] < A[x-1]){
  y = A[x];
  A[x] = A[x-1];
  A[x-1] = y;
  z++;
  }
}
printf("%d",A[i]);
if(i!=N-1){
    printf(" ");
}
}
  printf("\n");
  printf("%d",z);
  printf("\n");
return 0;

}

