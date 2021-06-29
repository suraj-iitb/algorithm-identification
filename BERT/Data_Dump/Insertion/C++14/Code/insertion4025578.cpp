//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define per(i, n) for(i=(n);i>0;i--)
#define repx(i, n, x) for(i=(x);i<(n);i++)
#define xper(i, n, x) for(i=(n);i>(x);i--)
#define pback push_back

//c++def
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
void prt(int A[], int n){
	int i;
	rep(i, n){
		printf("%d", A[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	int a[2000];
	int n;
	int tmp;
	int i, j;
	cin >> n;
	rep(i, n) cin >> a[i];
	prt(a,n);
	repx(i, n, 1){
		tmp = a[i];
		j = i -1;
		while(j>=0 && a[j] > tmp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
		prt(a, n);
	}
}



