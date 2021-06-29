#include<bits/stdc++.h>
#include<vector>
#include<deque>
#include<list>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int main() {

	int n;
	int a[101];

	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n-1)cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;

	for(int i=1; i<n; i++){
		int v=a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		rep(i,n-1)cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}

	return 0;
}

