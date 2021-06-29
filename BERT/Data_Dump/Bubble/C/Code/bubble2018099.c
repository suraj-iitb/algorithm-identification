#include <stdio.h>
#define MAX_N 100

int main(){
	int i,j,k;
	int n,flag,tmp,cnt=0;
	int A[MAX_N];
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&A[i]);

	flag = 1;
	while(flag){
		flag = 0;
		for(j=n-1; j>=1; j--){
			if(A[j] < A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				cnt++;
				flag = 1;
			}
		}
	}

	for(k=0; k<n; k++){
		if(k != n-1) printf("%d ",A[k]);
		else printf("%d\n",A[k]);
	}
	printf("%d\n",cnt);

	return 0;
}
