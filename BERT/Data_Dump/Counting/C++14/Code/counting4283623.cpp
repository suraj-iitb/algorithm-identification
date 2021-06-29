#include<bits/stdc++.h>
using namespace std;

void countingsort(vector<int>&a,vector<int>&b,int k){
	vector<int>c(k+1,0);
	for(int i=0;i<a.size();++i)++c.at(a.at(i));
	for(int i=1;i<=k;++i)c.at(i)+=c.at(i-1);
	for(int i=a.size()-1;i>=0;--i){
		b.at(c.at(a.at(i))-1)=a.at(i);
		--c.at(a.at(i));
	}
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n,k=0;
	cin>>n;
	vector<int>a(n),b(n);
	for(auto&i:a){
		cin>>i;
		k=max(k,i);
	}
	countingsort(a,b,k);
	cout<<b.at(0);
	for(int i=1;i<n;++i)cout<<" "s<<b.at(i);
	cout<<"\n"s;
}
