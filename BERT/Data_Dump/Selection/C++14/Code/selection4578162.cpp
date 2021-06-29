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
	int c = 0;
	rep(i, N-1){
		int minj = i;
		for(int j= i+1; j < N; j++){
			if(a.at(j)< a.at(minj)) minj = j;
		}
		if(i != minj){
			int b = a.at(minj);
			a.at(minj) = a.at(i);
			a.at(i) = b;
			c++;
		}
	}
	rep(i,N){
		if(i != N-1){
			cout << a.at(i) << " ";
		}else{
			cout << a.at(i) << endl;
		}
	}
	cout << c << endl;
}

