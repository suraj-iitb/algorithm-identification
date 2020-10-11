#include <stdio.h>
#define N 10001
#define MAX(a,b) ((a>b)?(a):(b))

int main(void){
	int a[N];
	int i,j,n,k,sum;
	int max=-1;
	for(i=0;i<N;i++) a[i]=0;

	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		max=MAX(max,k);
		a[k]++;
	}

	for(i=0;i<=max;i++){
		if(max!=i){
			for(j=0;j<a[i];j++){
				printf("%d ",i);
			}
		}
		else{
			for(j=0;j<a[i];j++){
				if(j!=a[i]-1) printf("%d ",i);
				else printf("%d",i);
			}
		}
	}
	printf("\n");
	return 0;
}
