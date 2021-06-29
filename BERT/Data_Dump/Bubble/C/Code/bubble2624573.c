#include<stdio.h>
int A[1000];
int cnt = 0;

int main(){
	int n,i,j,v,w,flag;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	flag = 1;
	while(flag){
		flag = 0;
		for(j=n-1;j>0;j--){
			if(A[j] < A[j-1]){
				w=A[j];
				A[j]=A[j-1];
				A[j-1]=w;
				flag=1;
				cnt++;
			}

		}
	}
	
	for(i=0;i<n-1;i++)printf("%d ",A[i]);
	printf("%d\n",A[n-1]);
	printf("%d\n",cnt);
	
	
	
	
	return 0;
}
