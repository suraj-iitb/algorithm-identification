#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS (1e-10)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int a[100];
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
	}
	rep(i, n) {
		if (i)printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		rep(i, n) {
			if (i)printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
}
