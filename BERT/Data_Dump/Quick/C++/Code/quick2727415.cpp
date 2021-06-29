#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct card{
	string suit; 
	int num;
	int id;
};

int partition(card a[], int p, int r){
	int x = a[r].num;
	int i = p-1;

	FOR(j,p,r){
		if(a[j].num <= x){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void quicksort(card a[],int p, int r){
	if(p < r){
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

bool isstable(card a[],int n){
	rep(i,n-1){
		if(a[i].num == a[i+1].num && a[i].id > a[i+1].id) return false;
	}
	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	card a[n];
	rep(i,n) {
		cin >> a[i].suit >> a[i].num;
		a[i].id = i;
	}

	quicksort(a,0,n-1);
	cout << (isstable(a,n) ? "Stable" : "Not stable") << endl;
	rep(i,n) cout << a[i].suit << " " << a[i].num << endl;
}
