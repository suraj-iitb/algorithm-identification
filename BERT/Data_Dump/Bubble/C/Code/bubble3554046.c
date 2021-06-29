#include<stdio.h>
int main(void){
	int n,t,flag,j,i;
	int cout=0;
	int A[100];
	scanf("%d\n",&n);
	for(t=0;t<n;t++){
		scanf("%d\n",&A[t]);
	}
	flag=1;
	i=0;
	while(flag){
		flag=0;
		for(j=n-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				int b;
				b=A[j];
				A[j]=A[j-1];
				A[j-1]=b;
				flag=1;
				cout++;
			}
		}
		i++;
	}
	for(t=0;t<n;t++){
		if(t==n-1){
			printf("%d\n",A[t]);
		}else{
			printf("%d ",A[t]);
		}
	}
	printf("%d\n",cout);
	
	return 0;
}
