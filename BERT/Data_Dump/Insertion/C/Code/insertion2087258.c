#include<stdio.h>

void insertionsort(int *A,int n){
		int i,j,k,v;
		
		for(i=1;i<n;i++){

			for(k=0;k<n-1;k++){
			printf("%d ",A[k]);
			}
			
			printf("%d\n",A[n-1]);
			v = A[i];
			j = i-1;
			while(j>=0&&A[j]>v){
				A[j+1]=A[j];
				j--;
				A[j+1]=v;
				
			}
			
		}
		
			for(k=0;k<n-1;k++){
			printf("%d ",A[k]);
			}
			printf("%d\n",A[n-1]);
}
	
	





int main(){
  int n,i,A[1000];
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  insertionsort(A,n);

  return 0;
}
