#include <stdio.h>

#define maxArraySize 1000

void output(int a[],int n){
	int c;
	for(c=0;c<n;c++){
		printf("%d",a[c]);
		if(c != n-1)printf(" ");
	}
	printf("\n");
}

void insersionSort(int A[],int N){
	int i,j,v;
	for(i=1;i<N;i++){
		v = A[i];
		j = i - 1;
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		output(A,N);
	}
}

int main(void){
	int a[maxArraySize],n,c;
	scanf("%d",&n);
	for(c=0;c<n;c++){
		scanf("%d",&a[c]);
	}
	output(a,n);
	insersionSort(a,n);
}
