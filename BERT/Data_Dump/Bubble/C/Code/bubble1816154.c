#include<stdio.h>
int main(void){
	int i,j,cnt=0,tmp,N,A[100];
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d",&A[i]);
	for(i=N;i>0;i--){
		for(j=0;j<i-1;j++){
			if(A[j]>A[j+1]){
				tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;
				cnt++;
			}
		}
	}
	printf("%d",A[0]);
	for(i=1;i<N;i++) printf(" %d",A[i]);
	printf("\n");
	printf("%d\n",cnt);
	return 0;
}
