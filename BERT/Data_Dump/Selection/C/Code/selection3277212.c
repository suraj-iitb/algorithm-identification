#include<stdio.h>

int main(){
  int N,A[100],i,j,temp,min,c=0,flag=0;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    min=i;
    flag=0;
    for(j=i;j<N;j++){
      if(A[j]<A[min]){
	flag=1;
	min=j;
      }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
    if(flag) c++;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
    

