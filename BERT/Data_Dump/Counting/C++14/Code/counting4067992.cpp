//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define repx(i, n, x) for(i=(x);i<(n);i++)
//c++def
using namespace std;

void countingsort(short *a, short *b, int k, int n){
	int i;
	int j;
	int c[10240];
	rep(i, k+1) c[i] = 0;
	for(j=1; j<=n;j++) c[a[j]]++;

	for(i=1; i<=k;i++) c[i] += c[i-1];

	for(j=n; j>=1;j--){
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
}

int main(){
	int n;
	int i;
	cin >> n;
	short a[n+2];
	short b[n+2];
	int max = -1;
	repx(i, n+1, 1){
		scanf("%hd",&a[i]);
		if(max <= a[i]) max = a[i];
	}
	countingsort(a, b, max, n);
	repx(i, n+1, 1){
		if(i!=1) printf(" ");
		printf("%hd", b[i]);
		if(i==n) printf("\n");
	}
}

