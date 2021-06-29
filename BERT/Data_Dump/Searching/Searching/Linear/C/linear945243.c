#include <stdio.h>
#define N 10000

int main(){
	int i, j;
	int n, q;
	int count=0;
	int s[N];
	int t[N];
	scanf("%d", &n);
	for( i=0; i<n; i++ ){
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for( i=0; i<q; i++ ){
		scanf("%d", &t[i]);
	}
	for( i=0; i<q; i++ ){
		for( j=0; j<n; j++ ){
			if( s[j]==t[i] ){
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
