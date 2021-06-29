#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back
   
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;

int main(){
	int N;
	cin>>N;
	vector<int> A;
	rep(i,N){
		int a;
		cin>>a;
		A.push_back(a);
	}
	rep(i,N-1)cout<<A[i]<<" ";
	cout<<A[N-1]<<endl;
	REP(i,1,N){
		int a = A[i];
		A.erase(A.begin()+i);
		int j=i-1;
		for(;a<A[j];j--);
		A.insert(A.begin()+j+1,a);
		rep(j,N-1){
			cout<<A[j]<<" ";
		}
		cout<<A[N-1]<<endl;
	}
	return 0;
}
