#include <stdio.h>

int main(void) {
	int n,mini,swaps=0;
	scanf(" %i",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf(" %i",&A[i]);
	}
	
	for(int i=0; i<=n-1; i++){
		mini = i;
		for(int j=i;j<=n-1;j++){
			if(A[j]<A[mini]){
				mini = j;
			}
		}
		int tmp=A[i];
		A[i]=A[mini];
		A[mini]=tmp;
    if(i!=mini){swaps++;}
	}
	
	for(int i=0;i<n;i++){
		if(i==n-1){
			printf("%i\n",A[i]);
		}else{
			printf("%i ",A[i]);
		}
	}
	printf("%i\n",swaps);
	return 0;
}
