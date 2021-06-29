#include<stdio.h>
int main(){
	int i,j,N,v,s;
	int A[1001];
	
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(s=0;s<N;s++){
		if(s == N-1){
			printf("%d\n",A[s]);
		}else{
		printf("%d ",A[s]);
		}
	}
	
	for(i=1;i<N;i++){
		
		
		
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(s=0;s<N;s++){
			if(s==N-1){
				printf("%d\n",A[s]);
			}else{
			printf("%d ",A[s]);
			}
		}
		
	}
}
