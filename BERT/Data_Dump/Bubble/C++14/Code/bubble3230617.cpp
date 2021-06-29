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
	int n;
	cin >>n;
	VI a(n);
	rep(i,n) cin >>a[i];
	
	int flg=1, cnt =0;
	while(flg){
		flg=0;
		for(int j=n-1; j>=1; j--){
			if(a[j] < a[j-1]){
				swap(a[j], a[j-1] );
				flg=1; cnt++;
			}
		}
	}
	rep(i,n) cout <<a[i] << (i==n-1?"\n":" ");
	cout <<cnt <<"\n";
	return 0;
}


