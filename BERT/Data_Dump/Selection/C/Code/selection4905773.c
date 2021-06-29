#include <stdio.h>
int main(){
	int n,num[100],temp,min,t=0;
	scanf("%d",&n);
	for(int x=0;x<n;x++){
		scanf("%d",&num[x]);
	}
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i;j<n;j++){
			if(num[min]>num[j])
			min=j;
		}
		if(min!=i){
			temp=num[i];
			num[i]=num[min];
			num[min]=temp;
			++t;
		}
	}
	for(int y=0;y<n;y++){
		printf("%d",num[y]);
		if(y<n-1){printf(" ");
		}
	}
	printf("\n%d\n",t); 
}
