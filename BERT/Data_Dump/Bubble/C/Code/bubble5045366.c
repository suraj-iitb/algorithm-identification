#include<stdio.h>

int main(){

  int A[100],N,i,j,b,s=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);}
  
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	b=A[j];
	A[j]=A[j-1];
	A[j-1]=b;
	s++;}}}
for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1){printf(" ");}
 }
  printf("\n%d\n",s);
      return 0;}

