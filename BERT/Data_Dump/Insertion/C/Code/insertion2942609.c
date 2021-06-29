#include<stdio.h>
int main( ){
  int i,j,N;
  int A[100],v;

  scanf("%d",&N);
  if(N<1 && N>100){
    printf("N value is over\n");
  }
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 for(i=0;i<N;i++){
   if(i > 0){
     printf(" ");
   }
   printf("%d",A[i]);
 }
 printf("\n");
 
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while((j>=0)&&(A[j]>v)){
	A[j+1]=A[j];
	j--;
    }
	A[j+1]=v;
  
	for(j=0;j<N;j++){
	  if(j > 0){
	    printf(" ");
	  }
	    printf("%d",A[j]);
	  }
	
	printf("\n");
	}
  
 
  return 0;
}
      
      

