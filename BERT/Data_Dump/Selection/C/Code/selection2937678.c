#include<stdio.h>
int main(){
    int N,i,j,com,minj,num=0;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	/*selection sort*/
	for(i=0;i<=N-1;i++){
		minj = i;
		for(j=i;j<=N-1;j++){
			if(A[j]<A[minj]){
				minj = j;
			}
		}
		com = A[i];
		A[i] = A[minj];
		A[minj] = com;
		if(i != minj){
			num++;
		}
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i<N-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",num);
    return 0;
}
