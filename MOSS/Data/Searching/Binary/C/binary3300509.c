#include <stdio.h>
#include <stdlib.h>

int binarySearch(int);

int n;
int *S;

int main(){
	int q,C = 0,i;
	int T;

	scanf("%d",&n);
	S = (int *)malloc(sizeof(int) * n);
	for(i = 0;i < n;i++)
		scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i = 0;i < q;i++){
		scanf("%d",&T);
		C += binarySearch(T);
	}

	printf("%d\n",C);

	free(S);
	return 0;
}

int binarySearch(int T){
	int mid,left = 0,right = n;

	while(left < right){
		mid = (left + right) / 2;
		if(T == S[mid])
			return 1;
		else if(T > S[mid])
			left = mid+1;
		else if(T < S[mid])
			right = mid;
	}
	return 0;
}
