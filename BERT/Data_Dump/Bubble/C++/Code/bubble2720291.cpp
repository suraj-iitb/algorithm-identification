#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll cnt;
ll a[103];
ll n;

void bubbleSort(){
	bool flag = true;
	while(flag){
		flag = false;
		for(ll j = n-1; j>=1; j--){
			if(a[j] < a[j-1]) {
				swap(a[j],a[j-1]);
				flag = true;
				cnt++;
			}
		}
	}
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	rep(i,n) cin >> a[i];

	cnt = 0;
	bubbleSort();
	rep(i,n) cout << a[i] << (i == n-1 ? "\n" : " ");
	cout << cnt << endl;
}
