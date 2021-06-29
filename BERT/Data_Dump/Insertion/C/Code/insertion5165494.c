#include<stdio.h>

int main(){
  int N,k,i,j,v;
  scanf("%d",&N);
  int A[N];
  for(i = 1;i <= N; i++){
  scanf("%d",&A[i]);
  }
  for(i = 1; i <= N  ; i++){   
	      v = A[i];		
	      j = i-1;
	      while( j > 0 && A[j] > v)
		{
		  A[j+1]=A[j];  
		  j--;
		}
	      A[j+1] = v;
	      for(k = 1 ; k <= N ; k++){
		if(k == N)
		printf("%d\n",A[k]);
		else 
		printf("%d ",A[k]);
	      }
    }
  
  return 0;
}
