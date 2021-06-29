#include <stdio.h>

int main(void)
{
	int N;
	int i, j, x,min,count=0, flag=1;
	scanf("%d", &N);
	int a[N];
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	
	while(flag==1){
		flag=0;
		for(i=0;i<N;i++){
			min=i;
			for(j=i; j<N; j++){
				if(a[j]<a[min]){
					min=j;
					flag=1;
				}
			}
			x=a[i];
			a[i]=a[min];
			a[min]=x;
			if(a[i]!=a[min]) count++;
		}
	}
			
	for(i=0; i<N-1; i++){
		printf("%d ", a[i]);
		}
	printf("%d\n", a[N-1]);
	printf("%d\n", count);
	
	return 0;
}
