#include <stdio.h>
int bubble(int*, int);

int main(int argc, char const *argv[])
{
	int i, n, a[100];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	printf("\n%d\n", bubble(a, n));
	return 0;
}

int bubble(int *A, int n){
	int i, j, flag=1, temp, count;
	temp=count=i=0;
	while(flag){
		flag=0;
		for(j=n-1;j>0;j--){
			if(A[j]<A[j-1]){
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
				flag=1;
				count++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d", A[i]);
		if(i!=(n-1)){
			printf(" ");
		}
	}
	return count;
}
