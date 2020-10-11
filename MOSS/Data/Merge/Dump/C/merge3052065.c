#include<stdio.h>
#include<stdlib.h>
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int cnt=0;

int main(void) {
	int n,l,m,r,i;
	int *M;
	
	scanf("%d",&n);
	M=(int *)malloc(n * sizeof(int));
	for(i = 0; i <n; i++) scanf("%d",&M[i]);
		l = 0;
		r = n;
		mergeSort(M,l,r);
		for(i=0;i<n;i++) {
			if(i==n-1)printf("%d",M[i]);
			else printf("%d ",M[i]);
		}
		printf("\n");
		printf("%d\n",cnt);
		free(M);
		return 0;
}

	
	void merge(int M[],int l ,int m, int r) {
		int  p = m-l;
		int  q = r-m;
		int L[p],R[q];
		int i;
		
		for(i = 0; i<p;i++) L[i] = M[l+i];
		for(i=0;i<q;i++) R[i] = M[m+i];
		L[p] = 2000000000;
		R[q] = 2000000000;
		i=0;
		int j=0;
		for(int k = l; k < r; k++) {
			if(L[i]<=R[j]) {
				M[k]=L[i];
				i+=1;
				cnt++;
			}
			else {
				M[k]=R[j];
				j+=1;
				cnt++;
			}
		}
	}
	
	void mergeSort(int M[],int l,int r) {
		if(l+1 < r) {
			int m=(l+r)/2;
			mergeSort(M,l,m);
			mergeSort(M,m,r);
			merge(M,l,m,r);
		}
	}
