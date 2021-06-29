#include<stdio.h>

int main (void){
	int n, i, q;
	
	scanf("%d", &n);
	int S[n];
	
	for(i=0; i<n; i++){
		scanf(" %d", &S[i]);
		//printf("S%d\n", S[i]);
	}
	
	
	scanf("%d", &q);
	int T[q];
	
	for(i=0; i<q; i++){
		scanf(" %d", &T[i]);
		//printf("T%d\n", T[i]);
	}
	
	int k=0, ii, A[q], z;
	
	for(i=0; i<q; i++){//T
		for(ii=0; ii<n; ii++){//S
			if(T[i]==S[ii]){
				A[k]=S[ii];
				k++;
			//	printf("k++%d\n", k);
				for(z=0; z<k-1; z++){
					if(A[z]==S[ii]){
						//printf("A[z]==S[ii] %d %d\n", A[z], S[ii]);
					//	printf("k%d\n", k);
						k-=1;
					//	printf("k %d\n", k);
					}
				}
				
			}
		}
	}
	
	printf("%d\n", k);
	/*for(i=0; i<k-1; i++){
		printf("%d ", A[i]);
	}
	printf("%d", A[k]);
	*/
	
	
	return 0;
}
