#include<stdio.h>
#define MAX 100

int main()
{
  int i,j,N,key,result,A[MAX];
  
  scanf("%d",&N);
  if(N>=1&&N<=100){
    
    for(i=0;i<N;i++){
      
      result=scanf("%d",&A[i]);
      if(result>=N) break;

    }
   
  for(j=0;j<N;j++){
    
    key=A[j]; //ソート済み列A[1...j-1]にA[j]を挿入する。
    i=j-1;

    while(i>=0 && A[i]>key){

      A[i+1]=A[i];
      i--;
	
                           }
    A[i+1]=key;
    
    for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
    }
    printf("%d",A[i]);
    printf("\n");
                  }
            }
 return 0;  
}
