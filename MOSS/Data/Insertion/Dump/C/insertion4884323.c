#include<stdio.h>

void insertationSort(int* sort,int n);

int main(){

	int n=0,i=0;
	
	scanf("%d",&n);
	
	int sort[n];
	
	for(i=0;i<n;i++){
		
		scanf("%d",&sort[i]);
		
	}
	
	for(int k=0;k<n;k++){
		printf("%d",sort[k]);
		if(k<n-1){
			printf(" ");
			}
		else{
			printf("\n");
			}
	}
	
	insertationSort(sort,n);

}

//ソート関数
void insertationSort(int* sort,int n){

	int i=0,v=0,j=0;
	
	for(i=1;i<=n-1;i++){
		
		v=sort[i];
		
		j=i-1;
		
		while(j>=0 && sort[j]>v){
		
			sort[j+1]=sort[j];
			
			j--;
			
			}
			
			sort[j+1]=v;
		
			for(int k=0;k<n;k++){
				printf("%d",sort[k]);
				if(k<n-1){
					printf(" ");
				}
				else{
				printf("\n");
				}	
			}
			
	}
			
}

