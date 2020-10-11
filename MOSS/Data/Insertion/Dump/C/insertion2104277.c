#include <stdio.h>

int i, j, k, n, A[100];

void pr(){ for(j=0;j<n;j++)printf("%d%c",A[j],j==n-1?'\n':' ');}
int main(){
	scanf("%d", &n);
	while(i < n) scanf("%d", &A[i++]);
	for(i = 0; i < n; i++){
		for(j = i, k = A[i]; j > 0 && k < A[j-1]; j--) A[j] = A[j-1];
		A[j] = k;
		pr();
	}
	return 0;
}
