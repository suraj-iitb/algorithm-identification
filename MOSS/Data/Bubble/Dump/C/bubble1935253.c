#include <stdio.h>
int main(void){
	int N,n[100],A,i,j,t,z,flag;
	flag=1;
	scanf("%d\n",&N);
	for (i=0;i<N;i++){
		scanf("%d",&n[i]);
	}
	t=0;
	while (flag==1){
		flag=0;
	for (i=N-1;i>=1;i--){
			if(n[i-1]>n[i]){
				A=n[i-1];
				n[i-1]=n[i];
				n[i]=A;
				t++;
				flag=1;
			}
		}
	}
	for (i=0;i<N;i++){
		printf("%d",n[i]);
		if (i!=N-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",t);
	return 0;
}
