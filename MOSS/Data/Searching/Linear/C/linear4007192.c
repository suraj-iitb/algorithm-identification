#include<stdio.h>

int search(int* S, int n, int t){
	int i = 0;
	S[n] = t;
	while (S[i] != t) i++;
	return i != n;
}


int main(int argc, char const *argv[]) {
	int i, n, S[10001], q, t, c = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &S[i]);

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &t);
		if(search(S, n, t)) c++;
	}

	printf("%d\n", c);

	return 0;
}

