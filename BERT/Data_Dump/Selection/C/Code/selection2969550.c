#include<stdio.h>
#include<string.h>
int main(){
  int A[100],N,a,i,j,minj,temp,count=0,k,l;
  scanf("%d",&N);
    for(a=0;a<N;a++){
      scanf("%d",&A[a]);
    }
    for(i=0;i<=N-1;i++){
      minj=i;
      l=i;
      for(j=i+1;j<N;j++){
	if(A[j]< A[minj]){
	  minj=j;
	}
	
      }
      
      if(l!=minj){
	temp=A[i];
	A[i]=A[minj];
	A[minj]=temp;
	
	
	count++;
      }
    
    
 

    }
    
  
  for(i=0;i<N;i++){
    if(i!=N-1){
      printf("%d ",A[i]);
    }
    else{ printf("%d",A[i]);
    }
  }
  printf("\n");
  printf("%d\n",count);
 

return 0;
}




