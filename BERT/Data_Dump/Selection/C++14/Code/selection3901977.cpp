#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

constexpr int atcoder_mod = 1e9+7;

using namespace std;
using ll = long long;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N=in();
	auto R=vecin(N);
	int num=0;
	REP(i,N){
		auto res = min_element(R.begin()+i,R.end());
		if((R.begin()+i)!=res){
			iter_swap(R.begin()+i,res);
			num++;
		}
	}
	REP(i,N-1){
		cout << R[i] << ' ';
	}
	out(R[N-1]);
	out(num);

	return 0;
}

