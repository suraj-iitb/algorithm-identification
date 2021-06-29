#include<bits/stdc++.h>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;++i)
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
typedef pair<int,ll>Pil;
typedef pair<int,Pil>Piil;
typedef pair<P1,ll> P2;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	int x,y,sx,sy,cost;
};
int a[101];

int main() {

	int n;
	cin>>n;
	rep(i,n)cin>>a[i];

	int t=0;
	rep(i,n-1){
		int minj=i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[minj])minj=j;
		}
		int x=a[i];
		if(x!=a[minj])t++;
		a[i]=a[minj];
		a[minj]=x;
	}
	rep(i,n-1)cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
	cout<<t<<endl;

	return 0;
}

