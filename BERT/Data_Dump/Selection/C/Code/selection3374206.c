#include <stdio.h>

#define maxN 100

void select(int N,int A[]){
	int i,j,tmp,min,swc=0;
	for(i=0;i<N-1;i++){
		min = i;
		for(j=i;j<N;j++){
			if(A[j] < A[min]){
				min = j;
			}
		}
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
		if(min != i)swc++;
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i < N-1){
			printf(" ");
		}
	}
	printf("\n%d\n",swc);
}

int main(void){
	int c,n,a[maxN];
	scanf("%d",&n);
	for(c=0;c<n;c++){
		scanf("%d",&a[c]);
	}
	select(n,a);
}
