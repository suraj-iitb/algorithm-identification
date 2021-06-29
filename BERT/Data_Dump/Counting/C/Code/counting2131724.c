#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}

long max(long x,long y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}

main(){
	long i,j,n,k;
	long *A,*B,*C;
	scanf("%ld",&n);
	mymalloc(A,n+1);
	mymalloc(B,n+1);
	k=0;
	for(i=1;i<=n;i++){
		scanf(" %ld",&A[i]);
		k=max(A[i],k);
	}
	mymalloc(C,k+1);
	for(j=0;j<=k;j++){
		C[j]=0;
	}
	for(i=1;i<=n;i++){
		C[A[i]]++;
	}
	for(j=1;j<=k;j++){
		C[j]+=C[j-1];
	}
	for(i=n;i>0;i--){
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}
	for(i=1;i<=n;i++){
		printf("%ld",B[i]);
		if(i!=n){
			printf(" ");
		}
	}
	printf("\n");
	free(A);free(B);free(C);
	return 0;
}
