#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
	int vn,en,r;
	cin >> vn >> en >> r;
	vector<int> d(vn,INF);
	vector<vector<pair<int,int>>> e(vn);
	for(int i=0; i<en; i++){
		int a,b,dist;
		cin >> a >> b >> dist;
		e.at(a).push_back({dist,b});
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	d.at(r) = 0;
	for(auto i:e.at(r)) q.push(i);
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		if(d.at(p.second)<p.first) continue;
		d.at(p.second) = p.first;
		for(auto j:e.at(p.second)) q.push({j.first+p.first,j.second});
	}
	for(auto i:d) {
		if(i==INF) cout << "INF" << endl;
		else cout << i << endl;
	}
}
