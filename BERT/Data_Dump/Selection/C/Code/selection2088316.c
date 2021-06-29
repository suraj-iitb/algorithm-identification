#include<stdio.h>
int main(void){
	int i,j,N;
	int minj,temp,count,flg;
	scanf("%d",&N);
	int a[N];
	count=0;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}

	count=0;
	for(i=0;i<N-1;i++){
		minj=i;
		flg=0;
		for(j=i;j<N;j++){
			if(a[j]<a[minj]){
				minj=j;
				flg=1;			
			}
		}
		if(flg==1){
			count++;
			temp=a[i];
			a[i]=a[minj];
			a[minj]=temp;
		}
	}
	for(i=0;i<N-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[N-1]);
	printf("%d\n",count);

	return 0;
}
