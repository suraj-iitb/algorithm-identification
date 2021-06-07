#include <stdio.h>

int linearSearch(int *, int);

int n;

int main(void)
{
	int i, S[10001], q, T[500], c=0;
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for (i=0; i<q; i++) {
		scanf("%d",&T[i]);
	}
	
	for (i=0; i<q; i++) {
		if( linearSearch( S, T[i] ) != -1 ) c++;
	}
	
	printf("%d\n",c);
	
	return 0;
}

int linearSearch(int *S, int key)
{
	int i;
	i = 0;
	S[n] = key;
	while ( S[i] != key ) {
		i++;
	}
	if( i==n ) return -1;
	return i;
}
