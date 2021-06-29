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

vector<int> L,R;

int MergeSort(vector<int>& A,int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right-mid;
	REP(i,n1){
		L[i] = A[i+left];
	}
	REP(i,n2){
		R[i] = A[i+mid];
	}
	L[n1] = 1<<30;
	R[n2] = 1<<30;

	int li=0,ri=0;
	for(int i=left;i<right;i++){
		if(L[li]<=R[ri]){
			A[i] = L[li++];
		}
		else{
			A[i] = R[ri++];
		}
	}
	return li+ri;
}

int MergeSort(vector<int>& A,int left,int right){
	int sum = 0;
	if(left+1<right){
		int mid = (left+right)/2;
		sum += MergeSort(A,left,mid);
		sum += MergeSort(A,mid,right);
		sum += MergeSort(A,left,mid,right);
	}
	return sum;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N=in();
	L.resize(N+1);
	R.resize(N+1);
	auto A=vecin(N);
	
	int sum = MergeSort(A,0,N);
	REP(i,N-1){
		cout << A[i] << ' ';
	}
	out(A[N-1]);
	out(sum);
	return 0;
}

