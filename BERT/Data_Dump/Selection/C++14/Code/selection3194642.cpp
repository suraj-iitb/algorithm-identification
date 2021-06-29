#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
//#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<list>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
using namespace std;
typedef long long int llint;
typedef long double lldo;
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
/*
cout<<setprecision(20)
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1e9+7;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
//llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	int i,j,n,ans=0;cin>>n;
	int A[100];
	for(i=0;i<n;i++){cin>>A[i];}
	for(i=0;i<n;i++){
		int minj=i;
		for(j=i+1;j<n;j++){if(A[j]<A[minj]){minj=j;}}
		if(minj!=i){ans++;}
		swap(A[i],A[minj]);
	}
	for(i=0;i<n;i++){cout<<A[i]<<(i+1<n?" ":"\n");}
	cout<<ans<<endl;
	return 0;
}
