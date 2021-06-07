#include<stdio.h>

int main(void){
	const int n_max = 10000;
	int n, q, S[n_max+1], T, i, j, ans = 0;

	scanf("%d", &n);
	for(i=0; i<n; ++i)
		scanf("%d", S+i);
	scanf("%d", &q);
	for(i=0; i<q; ++i){
		scanf("%d", &T);
		S[n] = T;
		j = 0;
		while(S[j] != T)
			++j;
		if(j == n)
			continue;
		++ans;
	}
	printf("%d\n", ans);

	return 0;
}
