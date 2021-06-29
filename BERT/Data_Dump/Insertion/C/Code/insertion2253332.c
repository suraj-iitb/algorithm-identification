#include<stdio.h>

int main( ){

  int N=0,i,key,A[100],j,z;
 
  scanf("%d",&N);


  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    
  }
  
  for(z=0;z<N-1;z++){
    printf("%d ",A[z]);

  }

  printf("%d\n",A[z]);

    


  

for(i=1;i<N;i++){

  key=A[i];
    
  j=i-1;


  while(j>=0&&A[j]>key){
      
    A[j+1]=A[j];
    j--;
  }
    A[j+1]=key;


  for(z=0;z<N-1;z++){
    printf("%d ",A[z]);

  }

  printf("%d\n",A[z]);

    
 }

return 0;
}
      

  
