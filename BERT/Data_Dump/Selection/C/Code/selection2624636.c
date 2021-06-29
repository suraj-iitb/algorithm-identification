#include<stdio.h>
int A[1000];
int cnt=0;

int main(){
	int n,i,j,minj,w;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	
	
	for(i=0;i<n;i++){
		minj = i;
		for(j=i;j<n;j++){
			if(A[j] < A[minj])minj = j;
		}
		if(i==minj){;}
		else{
			w=A[i];
			A[i]=A[minj];
			A[minj]=w;
			cnt++;
		}
	}
	
	for(i=0;i<n-1;i++)printf("%d ",A[i]);
	printf("%d\n",A[n-1]);
	printf("%d\n",cnt);
	
	
	return 0;
}
