#include <stdio.h>

int main(void)
{
	int N;
	int i, j, x,count=0, flag=1;
	scanf("%d", &N);
	int a[N];
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	while(flag==1){
		flag=0;
		for(j=1;j<N;j++){
			if(a[j]<a[j-1]){
				x=a[j];
				a[j]=a[j-1];
				a[j-1]=x;
				count++;
				flag=1;
			}
		}
	}
	
	
	for(i=0; i<N-1; i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[N-1]);
	printf("%d\n", count);
	
	return 0;
}
