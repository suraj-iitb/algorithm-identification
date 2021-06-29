#include <stdio.h>
#define S 100000
#define T 50000

int main(){
	int i;
	int n, q;
	int l, r, m;
	int count = 0;
	int s[S];
	int t[T];

	scanf("%d", &n);
	for( i=0; i<n; i++ ){
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for( i=0; i<q; i++ ){
		scanf("%d", &t[i]);
	}
	for( i=0; i<q; i++ ){
		l=0;
		r=n;
		while( l<r ){
			m=(l+r)/2;
			if( s[m]==t[i] ){
				count++;
				break;
			}
			else if( t[i]<s[m] ) r=m;
			else if( t[i]>s[m] ) l=m+1;
		}
	}
	printf("%d\n", count);
	return 0;
}
