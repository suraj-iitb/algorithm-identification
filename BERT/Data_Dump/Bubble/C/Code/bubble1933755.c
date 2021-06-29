#include<stdio.h>

int main(void){
	
	int N,A[100],i,s,flag=1,count=0;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){scanf("%d",&A[i]);}
	
	while(flag==1){
		flag = 0;
		for(i=N-1;i>0;i--){
			
			if(A[i]<A[i-1]){
				
				s = A[i];
				A[i] = A[i-1];
				A[i-1] = s;
				flag=1;
				count ++;
				
			}
			
		}
		
	}
	
	for(i=0;i<N;i++){printf("%d",A[i]);if(i != N-1)printf(" ");}
	printf("\n%d\n",count);
	
	return 0;}
