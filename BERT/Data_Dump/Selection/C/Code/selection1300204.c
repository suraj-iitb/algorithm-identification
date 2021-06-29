#include<stdio.h>

int main(){

	int N,a[100];
	int i,j,b,min,temp,count=0;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<N-1;i++){
		min = i;
		b=0;
		for(j=i;j<N;j++){
			if(a[j] < a[min]) {
				min = j;
				b=1;
			}
		}
		if(b == 1){
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			count++;
		}
	}

	for(i=0;i<N;i++){
		printf("%d",a[i]);
		if(i==N-1)printf("\n");
		else printf(" ");
	}
	printf("%d\n",count);

	return 0;
}
