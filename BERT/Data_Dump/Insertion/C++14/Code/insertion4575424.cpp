#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int N;
	cin >> N;
	v1 a(N);
	rep(i, N){
		cin >> a.at(i);
	}
	rep(i, N){
		int j = i-1;
		int v = a.at(i);
		while(j >= 0 && a.at(j)>v){
			a.at(j+1) = a.at(j);
			a.at(j) = v;
			j--;
		}
		rep(k, N){
			cout << a.at(k);
			if(k == N-1) {
				cout << endl;
			}else{
				cout << " ";
			}
		}
	}
}

