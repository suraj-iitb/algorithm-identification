#include<stdio.h>
void output(int N,int A[]){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
void changearray(int N,int A[]){
  int i,j,v;
   for(i=1;i<N;i++){
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v){
	A[j+1]=A[j];
	j--;
      }
      A[j+1]=v;
      output(N,A);
   }
}

int main(){
  int i,j,N;
  int A[100];
    //input
    scanf("%d",&N);
    for(i=0;i<N;i++)scanf("%d",&A[i]);
    
    output(N,A);
    changearray(N,A);
    
    return 0;
}



