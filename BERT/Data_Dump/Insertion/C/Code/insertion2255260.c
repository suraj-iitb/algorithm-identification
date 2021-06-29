#include<stdio.h>

int main(){
  int A[100],i,j,v,N,k;
  
  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }

 for(k=0;k<=N-1;k++){
	printf("%d",A[k]);
	if(k<=N-2)printf(" ");
      }
      printf("\n");
  
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j >= 0 && A[j] > v){
      A[j+1]=A[j];
	j--;
	A[j+1]=v;
    }
      for(k=0;k<=N-1;k++){
	printf("%d",A[k]);
	if(k<=N-2)printf(" ");
      }
      printf("\n");
  }
  
    return 0;
}
