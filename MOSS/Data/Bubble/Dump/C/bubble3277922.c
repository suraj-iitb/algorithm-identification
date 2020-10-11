#include<stdio.h>
void bubbleSort(int*,int);
int main(){
	int a,b,i,j;
	int array[100];
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&array[i]);
	}
	bubbleSort(array,a);
	return 0;
}

void bubbleSort(int* x,int y){
	int i,j,flag=1,count=0;
	while(flag){
		flag=0;
		for(i=y-1;i>=1;i--){
			if(x[i] < x[i-1]){
				j=x[i];
				x[i]=x[i-1];
				x[i-1]=j;
				flag=1;
				count++;
			}
		}
	}
	for(i=0;i<y;i++){
		if(i==y-1){
			printf("%d\n",x[i]);
		}
		else{
			printf("%d ",x[i]);
		}
	}
	printf("%d\n",count);
}
