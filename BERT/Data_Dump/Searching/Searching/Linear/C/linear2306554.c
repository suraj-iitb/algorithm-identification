#include <stdio.h>
#define N 100000
int n, S[N];
int count(int );

int main()
{
	int i, a=0, q, T[N];

	scanf("%d", &n);

	for( i=0; i<n; i++){
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);

	for( i=0; i<q; i++){
		scanf("%d", &T[i]);
	}

	for( i=0; i<q; i++){
		if( count(T[i]) == 1 ) a++;
	}

	printf("%d\n", a);

	return 0;
}

int count(int num)
{
	int i;

	for( i=0; i<n; i++){
		if( S[i] == num )return 1;
	}

	return 0;
}
