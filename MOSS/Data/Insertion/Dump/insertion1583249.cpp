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

void heap_sort(int data[], int n){
	priority_queue<int, vi, greater<int> > q;
	for(int i = 0; i < n; i++) q.push(data[i]);
	for(int i = 0; i < n; i++){
		data[i] = q.top();
		q.pop();
	}
}

void insertion_sort(int data[], int n, int h){
	for(int j = 0; j < n; j++){
		if(j != 0) cout<<" ";
		cout<<data[j];
	}
	cout<<endl;
	
	for(int i = h; i < n; i+=h){

		int tmp = data[i];
		int j = i;
		while(j - h >= 0 && data[j - h] > tmp){
			data[j] = data[j - h];
			j-=h;
		}
		data[j] = tmp;


		for(int j = 0; j < n; j++){
			if(j != 0) cout<<" ";
			cout<<data[j];
		}
		cout<<endl;
	}
}

void shell_sort(int data[], int n){
	int h = 0;
	while(h * 3 + 1 < n) h = h * 3 + 1;
	while(h > 1){
		insertion_sort(data, n, h);
		h = ( h - 1) / 3;
	}
	insertion_sort(data, n , 1);
}

void merge(int data[], int l, int r, int d[]){
	if(r - l <= 0) return;

	int m = (l + r) / 2;

	merge(data, l, m, d);
	merge(data, m + 1, r, d);

	for(int i = l; i <= m; i++) d[i] = data[i];
	for(int i = m + 1, j = r; i <= r; i++, j--) d[i] = data[j];

	for(int i = l, j = r, k = l; k <= r; k++){
		if(d[i] <= d[j]){
			data[k] = d[i];
			i++;
		}
		else{
			data[k] = d[j];
			j--;
		}
	}
}

void merge_sort(int data[], int n){
	int d[MAX_SIZE];
	merge(data, 0, n , d);
}

void quick_sort(int data[], int l, int r){
	int i = l, j = r, p = data[(l + r) / 2];
	while(1){
		while(data[i] < p) i++;
		while(data[j] > p) j--;
		if(i >= j) break;
		swap(data[i], data[j]);
		i++;
		j--;
	}
	if(i - l > 1) quick_sort(data, l, i - 1);
	if(r - j > 1) quick_sort(data, j + 1, r);
}


int main(){
	int d[MAX_SIZE];
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) cin>>d[i];
	insertion_sort(d, n, 1);
	
}
