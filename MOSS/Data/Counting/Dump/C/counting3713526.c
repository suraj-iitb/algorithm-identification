#include <stdio.h>
#include<math.h>
#define MAX 2000005

int i,j,n;
int A[MAX], B[MAX], C[10000];

void countSort(int a[], int b[], int k){
	for (i = 0; i <= k; i++)
		C[i] = 0;
	for (j = 1; j < n+1; j++)
        C[a[j]]++;
    for (i = 1; i <= k; i++)
    	C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--){ 
       b[C[a[j]]] = a[j];
       C[a[j]]--;
    }
}


int main(void){
	scanf("%d ", &n);
	for(i=1; i<=n; i++)
		scanf("%d ", &A[i]);
	
	int max = A[1];
	for (i=2; i<=n; i++){
		if (A[i]>max)
			max = A[i];
	}
	
	countSort(A,B,max);
	
	for (i=1; i<=n; i++){
		if (i<n)
			printf("%d ", B[i]);
		else printf("%d\n", B[i]);
	}
	return 0;
}



