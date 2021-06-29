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
	auto V=vecin(N);
	
	REP(i,N){
		int q = V[i];
		int j=i-1;
		for(;j>=0;j--){
			if(V[j]>q){
				V[j+1] = V[j];
			}
			else break;
		}
		V[j+1] = q;

		REP(k,N-1){
			cout << V[k] << ' ';
		}
		out(V[N-1]);
	}

	return 0;
}

