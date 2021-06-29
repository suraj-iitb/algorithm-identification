#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

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
	auto A=vecin(N);
	int K=*max_element(ALL(A));
	vector<int> B(N),C(K+1,0);
	
	for(int i=0;i<N;i++){
		C[A[i]]++;
	}
	for(int i=1;i<=K;i++){
		C[i] += C[i-1];
	}
	for(int i=N-1;i>=0;i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}

	REP(i,N-1){
		cout << B[i] << ' ';
	}
	out(B[N-1]);

	return 0;
}

