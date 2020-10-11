#include <stdio.h>

int main(void){
	int array[100];
	int n;
	int i,j,flag,tmp,ex=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&array[i]);
	}
	flag = 1;
	i=0;
	while(flag){
		flag = 0;
		for(j=n-1;j>=i+1;--j){
			if(array[j]<array[j-1]){
				tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
				flag=1;
				ex++;
			}
		}
		i++;
	}
	for(i=0;i<n;++i){
		if(i)printf(" ");
		printf("%d",array[i]);
	}
	printf("\n%d\n",ex);
	return 0;
}
