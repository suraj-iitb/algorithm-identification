#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const int mod=998244353;
const llint big=2.19e18+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int part(vector<tuple<int,char,int>>&A,int L,int R){
	int x=L,i;
	for(i=L;i<R;i++){
		if(get<0>(A[i])<=get<0>(A[R])){
			swap(A[i],A[x]);
			x++;
		}
		
	}swap(A[x],A[R]);
	return x;
}
void quiso(vector<tuple<int,char,int>>&A,int L,int R){
	if(L>=R){return;}
	int mid=part(A,L,R);
	quiso(A,L,mid-1);
	quiso(A,mid+1,R);
}
int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,i;cin>>n;
	vector<tuple<int,char,int>>A(n);
	for(i=0;i<n;i++){
		char c;int x;cin>>c>>x;
		A[i]=mt(x,c,i);
	}
	quiso(A,0,n-1);
	bool sta=1;
	for(i=0;i<n-1;i++){
		if(get<0>(A[i])==get<0>(A[i+1])&&get<2>(A[i])>get<2>(A[i+1])){sta=0;break;}
	}
	cout<<(sta?"Stable":"Not stable")<<endl;
	for(auto it:A){cout<<get<1>(it)<<" "<<get<0>(it)<<endl;}
	
	return 0;
}
