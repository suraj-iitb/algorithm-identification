#include<stdio.h>
int main(){
	int s;
	
	scanf("%d",&s);

	int i,j;
	int temp;
	int data[s];
	
	for(i=0;i<s;i++){
		scanf("%d",&data[i]);
	}
	
	for(i=0;i<s;i++){
		temp=data[i];
		j=i;
		while(j>0&&data[j-1]>temp){
			data[j]=data[j-1];
			j--;
		}
		data[j]=temp;
		for(j=0;j<s;j++){
			printf("%d",data[j]);
			if(j+1!=s){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}


