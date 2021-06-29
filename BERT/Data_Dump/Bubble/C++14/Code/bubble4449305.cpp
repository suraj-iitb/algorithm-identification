#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int>v(n); for(auto&i:v)cin>>i;
	int cnt=0;
	for(int i=0;i<n;++i){
		for(int j=n-2;j>=i;--j){
			if(v.at(j)>v.at(j+1)){
				int tmp=v.at(j);
				v.at(j)=v.at(j+1);
				v.at(j+1)=tmp;
				++cnt;
			}
		}
	}
	for(int i=0;i<n;++i){
		cout<<v.at(i);
		if(i!=n-1)cout<<" "s;
		else cout<<"\n"s<<cnt<<"\n"s;
	}
}
