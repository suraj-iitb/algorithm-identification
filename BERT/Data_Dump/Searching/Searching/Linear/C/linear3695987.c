#include <stdio.h>

int i;
/*
int linearSearch(int n, int A[], int key){
	i = 0;
	A[n] = key;
	while (A[i] != key)
		i++;
	if (i == n)
		return -1;
	return i;
}
*/

int main(void) {
	int n,q,j,count=0;
	
	scanf("%d",&n);
	int S[n];
	
	for(i=0; i<n; i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	int T[q];
	
	for(i=0; i<q; i++){
		scanf("%d",&T[i]);
		for (j=0; j<n; j++){
			if (T[i]==S[j]){
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);
	
	return 0;
}

