#include<stdio.h>

int main(void){
	const int n_max = 100000;
	int n, q, S[n_max+1], T, i, ans = 0;
	int left, right, mid;

	scanf("%d", &n);
	for(i=0; i<n; ++i)
		scanf("%d", S+i);
	scanf("%d", &q);
	for(i=0; i<q; ++i){
		scanf("%d", &T);
		left = 0;
		right = n;
		if(T < S[0] || S[n-1] < T)
			continue;
		while(left < right){
			mid = (left+right)/2;
			if(T == S[mid]){
				++ans;
				break;
			}
			if(T > S[mid]){
				left = mid +1;
			}else if(T < S[mid]){
				right = mid;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
