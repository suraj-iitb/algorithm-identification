#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2> 
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main(){
	int n , cnt=0;
	cin >>n;
	VI a(n);
	rep(i,n) cin >>a[i];
	
	rep(i,n){
		int minj=i;
		rep2(j, i, n){
			if(a[j] < a[minj]) minj = j;
		}
		if(a[i] != a[minj]){
			swap(a[i], a[minj]);
			cnt++;
		}
	}
	
	rep(i,n) cout <<a[i] << (i==n-1?"\n":" ");
	cout <<cnt <<"\n";
	return 0;
}


