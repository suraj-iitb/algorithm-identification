#include<stdio.h>

int main(){
	int N,a[100],i,j,k,temp;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++) scanf("%d",&a[i]);
	for(i=0;i<N-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[i]);
	
	for(i=1;i<N;i++){
		temp = a[i];
		j = i-1;
		while(j >= 0 && a[j] > temp){
			a[j+1] = a[j];
			j--;
			a[j+1] =temp;
		}
		for(k=0;k<N-1;k++) printf("%d ",a[k]);
		printf("%d\n",a[k]);
	}
	return 0;
}
