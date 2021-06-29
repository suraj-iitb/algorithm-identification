#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int S =0;
void merge(vector<ll>& a, int left, int mid, int right){
	int n1 = mid -left;
	int n2 = right - mid;
	vector<ll> L(n1);
	vector<ll> R(n2);
	rep(i, n1){
		L.at(i) = a.at(left + i);
	}
	L.push_back(1e10);
	rep(i, n2){
		R.at(i) = a.at(mid + i);
	}
	R.push_back(1e10);
	int i = 0;
	int j = 0;
	for(int k = left; k < right; k++){
		S++;
		if(L.at(i) > R.at(j)){
			a.at(k) = R.at(j);
			j++;
		}else{
			a.at(k) = L.at(i);
			i++;
		}
	}
}

void mergesort(vector<ll>& a, int left, int right){
	if(left +1 == right) return;
	int mid = (right + left)/2;
	mergesort(a, left, mid);
	mergesort(a, mid, right);
	merge(a, left, mid, right);
}

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n){
		int b;
		scanf("%d", &b);
		a.at(i) = b;
	}
	mergesort(a, 0, n);
	rep(i, n){
		int b = a.at(i);
		printf("%d", b);
		if(i != n-1) printf(" ");
	}
	cout << endl << S << endl;;
}

