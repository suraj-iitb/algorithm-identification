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
	bool flag = true;
	int count = 0;
	while(flag){
		flag = false;
		for(int j = N-1; j>0; j--){
			if(a.at(j)<a.at(j-1)){
				int t = a.at(j);
				a.at(j) = a.at(j-1);
				a.at(j-1) = t;
				count++;
				flag = true;
			}
		}
	}
	rep(i, N){
		if(i != N-1){
			cout << a.at(i) << " ";
		}else{
			cout << a.at(i) << endl;
		}
	}

	cout << count << endl;
}

