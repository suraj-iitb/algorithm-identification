#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int>a(n); for(auto&&i:a)cin>>i;
	for(int i=1;i<n;++i){
		cout<<a.at(0);
		for(int k=1;k<n;++k){
			cout<<" "s<<a.at(k);
		}
		cout<<"\n"s;
		int v=a.at(i),j=i-1;
		while(j>=0&&a.at(j)>v){
			a.at(j+1)=a.at(j);
			--j;
		}
		a.at(j+1)=v;
	}
	cout<<a.at(0);
	for(int i=1;i<n;++i){
		cout<<" "s<<a.at(i);
	}
	cout<<"\n"s;
}
