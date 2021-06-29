#include <stdio.h>
#define INFTY 1000000001
int N,n[500000],i,j,k,C=0;
int n1,n2,Lf[500000],Rf[500000];

void merge (int L,int M,int R){
	n1= M-L;
	n2= R-M;
	for (i=0;i<n1;i++){
		Lf[i]=n[L+i];
//		printf("%d",Lf[i]);
	}
	for (i=0;i<n2;i++){
		Rf[i]=n[M+i];
//		printf("%d",Rf[i]);
	}
	Lf[n1]=INFTY;
	Rf[n2]=INFTY;
	i=0;
	j=0;
	for (k=L;k<R;k++){
		if (Lf[i]<Rf[j]){
			n[k]=Lf[i];
//			printf("\n%d",n[k]);
			i=i+1;
		}else{
			n[k]=Rf[j];
//			printf("\n%d",n[k]);
			j=j+1;
		}
		C++;
	}
}


void mergeSort(int L,int R){
	if (L+1<R){
		int M;
		M=(L+R)/2;
		mergeSort(L,M);
		mergeSort(M,R);
		merge(L,M,R);
	}
}

int main(void){


	scanf("%d\n",&N);
	for (i=0;i<N;i++){
		scanf("%d",&n[i]);
	}
	mergeSort(0,N);

	for (i=0;i<N;i++){
		printf("%d",n[i]);
		if (i!=N-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",C);
	return 0;
}
