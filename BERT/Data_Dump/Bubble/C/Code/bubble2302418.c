#include<stdio.h>
int main(void){
	int A[100];
	int N,i,j,v;
	int cunt=0;
	int cunt2=0;
	
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	
	for(j=0;j<N;j++){
		for(i=N-1;i>=j+1;i--){
			if(A[i-1]>A[i]){
				v=A[i-1];
				A[i-1]=A[i];
				A[i]=v;
				cunt++;
			}
		}
	}
	for(i=0;i<N;i++){
		if(i>0)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n%d\n",cunt);
	return 0;
}
