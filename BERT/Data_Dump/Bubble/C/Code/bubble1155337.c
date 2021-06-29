#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int data[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	int swap=0,temp;
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(data[j-1]>data[j]){
				temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
				swap++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",data[i]);
		if(i+1!=n){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",swap);
	return 0;
}
