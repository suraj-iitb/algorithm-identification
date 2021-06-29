#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
const int INF = 10000000;


const int MAX_SIZE = 100;

int d[MAX_SIZE];
int ans = 0;


void selection_sort(int n){
	for(int i = 0; i < n; i++){
		int minj = i;
		for(int  j = i; j < n; j++){
			if(d[j] < d[minj]){
				minj = j;
			}
		}
		if(d[i] != d[minj]) ans++;
		swap(d[i],d[minj]);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) cin>>d[i];
	selection_sort(n);
	for(int i = 0; i < n; i++){
		if(i != 0) cout<<" ";
		cout<<d[i];
	}
	cout<<endl;
	cout<<ans<<endl;
}
