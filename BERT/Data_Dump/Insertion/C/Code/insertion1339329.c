#include<stdio.h>
int main(){
	int i,j,N,a[100],key;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&a[i]);
	for(i=0;i<N;i++){
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		for(j=0;j<N;j++){
			printf("%d",a[j]);
			if(j!=N-1)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}