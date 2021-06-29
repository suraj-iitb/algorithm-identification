#include <stdio.h>
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int main(void){
	int i,j,l,N;
	int a[100];
	scanf("%d",&N);
	for(i=0;i<N-1;i++){
		scanf("%d ",&a[i]);
	}
	scanf("%d",&a[N-1]);
	for(l=0;l<N;l++){
		for(j=0;j<N-1;j++){
					printf("%d ",a[j]);
		}
		printf("%d",a[N-1]);
		printf("\n");
		for(i=l;0<=i;i--){
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);
			}
		}
	}
}
