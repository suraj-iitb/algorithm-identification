#include <stdio.h>

int bubble(int [],int );
int main(void){
	int n,A[100];
	int i,c;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	c=bubble(A,n);
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i!=n-1) printf(" ");
		else printf("\n");
	}
	printf("%d\n",c);
	return 0;
}

int bubble(int A[],int n){
	int i,flag,a,count=0;
	flag=1;
	while(flag){
		flag=0;
		for(i=n-1;i>0;i--){
			if(A[i]<A[i-1]){
				a=A[i];
				A[i]=A[i-1];
				A[i-1]=a;
				count++;
				flag=1;
			}
		}
	}
	return count;
}
