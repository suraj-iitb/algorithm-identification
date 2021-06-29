#include <stdio.h>

int selection(int A[],  int n){
	int i, j, count, temp, minj;
	count=temp=minj=0;
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		temp=A[i];
		A[i]=A[minj];
		A[minj]=temp;
		if(minj!=i){
			count++;
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

int main(int argc, char const *argv[])
{
	int i, n, a[100];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}	
	printf("\n%d\n", selection(a, n));
	return 0;
}


