
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	int temp;
	int data[n];
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	for(i=0;i<n;i++){
		temp=data[i];
		j=i;
		while(j>0&&data[j-1]>temp){
			data[j]=data[j-1];
			j--;
		}
		data[j]=temp;
		for(j=0;j<n;j++){
			printf("%d",data[j]);
      if(j!=n-1)printf(" ");
		}
		printf("\n");
	}
	return 0;
}

