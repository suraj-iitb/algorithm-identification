#include<stdio.h>

int main(){
  
  int N,A[100],i,j,v,k;
  
  scanf("%d",&N);
  
  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }

for(i=1; i <= N; i++){
for(v=0; v< N; v++){
      printf("%d",A[v]);
      if(v==N-1)
	break;
      else printf(" ");
 }

printf("\n");

v=A[i];
  j=i-1;

  while(j >=0 && A[j] > v){
    A[j+1]=A[j];
    j--;
    A[j+1]=v;
  }
  }
 
  return 0;
  }
