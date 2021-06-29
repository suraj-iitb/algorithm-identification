#include<stdio.h>
int main(void){
	int i,j,N,k;
	int v;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}

	for (i=0;i<N;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
			a[j+1]=v;
		
	for(k=0;k<N-1;k++){
		printf("%d ",a[k]);
	}
	printf("%d\n",a[N-1]);
	}
	return 0;
}
