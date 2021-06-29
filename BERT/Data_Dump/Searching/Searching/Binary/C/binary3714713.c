#include <stdio.h>

int binarySearch(int A[], int key, int n){
	int left = 0;
	int right = n;
	while(left < right){
		int mid = (left + right)/2;
		if(A[mid] == key)return 1;
		if(A[mid] < key)left = mid + 1;
		if(A[mid] > key)right = mid;
	}  
	return 0;
}

int main(void) {
	int n;
	int S[100000];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)scanf("%d", &S[i]);
	int q;
	scanf("%d",&q);
	int cnt = 0;
	for(int i = 0; i < q; i++){
		int temp;
		scanf("%d",&temp);
		cnt += binarySearch(S, temp, n);
	}
	printf("%d\n",cnt);
	return 0;
}

