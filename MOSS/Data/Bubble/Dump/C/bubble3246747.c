#include <stdio.h>

int main(void){
	int n,flag,count,x,i,tmp;
	count = 0;
	scanf("%d", &n);
	int value[n];
	for(i=0;i<n;i++){
			scanf("%d", &x);
			value[i] = x;
	}
	flag=1;
	while(flag){
		flag = 0;
		for(int j=n-1;j>0;j--){
			if(value[j] < value[j-1]){
				tmp = value[j];
				value[j] = value[j-1];
				value[j-1] = tmp;
				flag = 1;
				count++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d", value[i]);
		if(i==n-1){
			printf("\n");
		} else{
			printf(" ");
		}
	}
	printf("%d\n", count);
}

