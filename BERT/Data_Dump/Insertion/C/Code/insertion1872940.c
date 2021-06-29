#include<stdio.h>
#include<math.h>
int main(void){
	int i, j, k, n,v;
	int A[1000]={0};
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	
		for(k=0; k<n; k++){
			if(k != n-1) printf("%d ", A[k]);
			else printf("%d\n", A[n-1]);
		}
		
	for(i=1; i<n; i++){
		v = A[i];
		j = i-1;
		while(j>=0 && A[j] > v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0; k<n; k++){
			if(k != n-1) printf("%d ", A[k]);
			else printf("%d\n", A[n-1]);
		}
	}
	
	
return 0;
}
