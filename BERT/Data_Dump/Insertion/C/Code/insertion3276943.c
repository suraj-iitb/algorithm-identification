#include <stdio.h>
int main (){
  int a,b,c,i,j,v,N;
  
    
    scanf("%d",&N);
    int A[N];
    for(b=0;b<N;b++){
      scanf("%d",&A[b]);
    }
 for(a=0;a<N;a++){
    if(a==N-1){  
      printf("%d\n",A[a]);
    }
    else{
      printf("%d ",A[a]);
 }
 }
  
    for(i=1;i<N;i++){
      v=A[i];
      j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(c=0;c<N;c++){
    if(c==N-1){
printf("%d\n",A[c]);
    }
    else{
      printf("%d ",A[c]);
	   
    }
    }
    }
    return 0;
  }

 
  
  
    
  

