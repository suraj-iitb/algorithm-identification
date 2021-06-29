#include<stdio.h>
#include<stdlib.h>
int main(){
  int N,i,j,*A,v;
  
  scanf("%d",&N);
  A=malloc(N*sizeof(int*));
  for(i=0;i<N;i++){
  
    scanf("%d",&A[i]);
    if(i==N-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  
 
  /*irekae*/
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
     
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      
     }
     A[j+1]=v;
     for(j=0;j<N;j++){
       if(j==N-1) printf("%d\n",A[j]);
       else printf("%d ",A[j]);
      
     }
    
  }
  
 
  return 0;
}

