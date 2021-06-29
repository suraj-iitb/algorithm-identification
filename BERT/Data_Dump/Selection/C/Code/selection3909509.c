#include<stdio.h>

void selection_sort(int *number,int array_num){
	int flag;
	int p;
	int i,j;
	int temp=0;
	int c=0;
	for(i=0;i<array_num-1;i++){
		flag=0;
		p=i;
		for(j=i+1;j<array_num;j++){
			if(number[p]>number[j]){
				p=j;
				flag=1;
			}
		}
		if(flag){
			temp=number[i];
			number[i]=number[p];
			number[p]=temp;
			c++;
		}
	}
	for(int k=0;k<array_num;k++){
			if(k!=array_num-1){printf("%d ",number[k]);}
			else{printf("%d\n",number[k]);}
	}
	printf("%d\n",c);
}

int main(void){
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	selection_sort(A,n);
	return 0;
	
}
