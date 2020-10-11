#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,n,nn,k=10000,*A,*B,*C;
	scanf("%d",&n);
	nn=n;
	A = malloc(sizeof(int)*n+2);
	i=1;
	while(nn--){
		scanf("%d",(A+i));
		i++;
	}

	B = malloc(sizeof(int)*n+2);
	C = malloc(sizeof(int)*k+2);
	for(i=0; i<=k; i++){
		C[i] = 0;
	}
	for(j=1; j<=n; j++){
		C[A[j]]++;
	}
	for(i=1; i<=k; i++){
		C[i] = C[i] + C[i-1];
	}
	for(j=n; j>=1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	for(i=1; i<=n; i++){
		i != n ? printf("%d ",B[i]):printf("%d\n",B[i]);
	}
	return 0;
}
