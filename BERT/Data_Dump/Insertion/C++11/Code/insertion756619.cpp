#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define VIEW(dat) for(auto v : dat){cout<<v<<endl;}

int main(){
	int n,a;
	cin>>n;
	vector<int> dat;
	rep(i,n){
		cin>>a;
		dat.push_back(a);
	}
	
	
	for(int k=0;k<dat.size()-1;k++){
		cout<<dat[k]<<" ";
	}
	cout<<dat[dat.size()-1]<<endl;
	
	for(int j=1;j<dat.size();j++){
		auto key = dat[j];
		auto i =j-1;
		while(i>=0&&dat[i]>key){
			dat[i+1]=dat[i];
			i--;
		}
		dat[i+1]=key;
		
		
		for(int k=0;k<dat.size()-1;k++){
			cout<<dat[k]<<" ";
		}
		cout<<dat[dat.size()-1]<<endl;
	}
	
	return 0;
}
