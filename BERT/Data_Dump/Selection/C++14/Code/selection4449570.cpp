#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int>v(n); for(auto&i:v)cin>>i;
	int cnt=0;
	for(int i=0;i<n-1;++i){
		int mn=i;
		for(int j=i+1;j<n;++j){
			if(v.at(j)<v.at(mn))mn=j;
		}
		if(i!=mn){
			int tmp=v.at(i);
			v.at(i)=v.at(mn);
			v.at(mn)=tmp;
			++cnt;
		}
	}
	for(int i=0;i<n;++i){
		cout<<v.at(i);
		if(i!=n-1)cout<<" "s;
		else cout<<"\n"s<<cnt<<"\n"s;
	}
}
