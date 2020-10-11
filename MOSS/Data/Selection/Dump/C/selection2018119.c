#include <stdio.h>
#define MAX_N 100

int main(){
	int i,j,k,l;
	int n,tmp,min,cnt=0;
	int A[MAX_N];
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&A[i]);

	for(j=0; j<n; j++){
		min = j;
		for(k=j; k<n; k++){
			if(A[k] < A[min]) min = k;
		}
		tmp = A[j];
		A[j] = A[min];
		A[min] = tmp;
		if(j != min) cnt++;
	}

	for(l=0; l<n; l++){
		if(l != n-1) printf("%d ",A[l]);
		else printf("%d\n",A[l]);
	}
	printf("%d\n",cnt);
	return 0;
}
