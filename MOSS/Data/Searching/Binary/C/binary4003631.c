#include <stdio.h>

int binarysearch(int N, int Q, int n[], int q[]){
	int i, mid, first, last;
	int count = 0;
	for(i = 0; i < Q; i++){
		first = 0;last = N;
		while(first < last){
			mid = (first + last) / 2;
			if(q[i] == n[mid]){
				count++;
				break;
			}
			else if(q[i] < n[mid]){
				last = mid;
			}
			else{
				first = mid + 1;
			}
		}
	}
	return count;
}

int main(void){
	int N, Q, i;
	int n[100000], q[50000];
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &n[i]);
	}
	scanf("%d", &Q);
	for(i = 0; i < Q; i++){
		scanf("%d", &q[i]);
	}
	printf("%d\n", binarysearch(N, Q, n, q));
	return 0;
}
