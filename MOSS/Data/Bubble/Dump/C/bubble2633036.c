#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int* A, int N);

int main(void){
	int n;
	scanf("%d",&n);
	
	int *num;
	num = (int *)malloc(sizeof(int)*n);
	if(num == NULL){
		printf("failure\n");
		exit(1);
	}
	
	//int num[100];
	int i,chnum;

	for(i=0;i<n;i++){
		scanf("%d",(num+i));
	}

	chnum=bubbleSort(num,n);

	printf("%d",num[0]);
	for(i=1;i<n;i++){
		printf(" %d",*(num+i));
	}
	printf("\n%d\n",chnum);

	free(num);

	return 0;
}

int bubbleSort(int *num,int n){
	int esc,j,flag=1,chnum=0;
	while(flag){
		flag=0;
		for(j=n-1;j>0;j--){
			if(num[j]<num[j-1]){
				esc=num[j];
				num[j]=num[j-1];
				num[j-1]=esc;
				flag=1;
				chnum++;
			}
		}
	}
	return chnum;
}
