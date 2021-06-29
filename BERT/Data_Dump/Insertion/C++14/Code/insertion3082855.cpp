#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;

const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);

	int n; cin >>n;
	VI a(n);
	rep(i, n) cin >> a[i];
	
	rep(k, n) cout << a[k] <<(k==n-1? "\n":" ");
	rep2(i, 1, n){
		int v =a[i], j =i -1;
		while(j >=0 && a[j] > v){
			a[j+1] = a[j]; j--;
		}
		a[j+1] = v;
		rep(k, n) cout << a[k] <<(k==n-1? "\n":" ");
	}
	
	return 0;
}

