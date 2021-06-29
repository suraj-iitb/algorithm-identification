#include<stdio.h>
int main(void){
	
	int n,i,j,jump,cnt=0,min;
	scanf("%d",&n);
	
	int A[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(A[min]>A[j]){
				min=j;	
			}
			
		}
		
		if(i!=min){
				jump=A[i];
				A[i]=A[min];
				A[min]=jump;
				cnt++;
			}
		
	}
	
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[i]);
	printf("%d\n",cnt);
	return 0;
}
