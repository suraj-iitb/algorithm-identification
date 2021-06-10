#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
struct node{
	long long cost;
	set<pair<long long,long long>> p;
};

int main(void){
	long long v,e,r,i;
	vector<node> a;
	cin >> v >> e >> r;
	a.resize(v);
	for(i=0;i<v;i++) a[i].cost = -1;
	for(i=0;i<e;i++) {
		long long x,y,d;
		cin >> x >> y >> d;
		a[x].p.insert(make_pair(d,y));
		//a[x].p.first = d;
		//a[x].p.second = y;
	}

/*for(i=0;i<v;i++) {
cout << i << " the route\n";
for(auto itr = a[i].p.begin(); itr != a[i].p.end(); itr++) cout << (*itr).first << " "<< (*itr).second << endl;
cout << endl;
}*/
	
	//a[r].cost = 0;
	set<pair<long long, long long>> que;
	que.insert(make_pair(0,r));
	auto hitr = que.begin();
//cout << "start town: " << (*hitr).second << endl;
	//long long now_cost = 0;
	while (!que.empty()) {
		auto itr = que.begin();
		long long temp_cost = (*itr).first;
		long long next_town = (*itr).second;
//cout << "now in " << next_town << " cost: " << temp_cost << endl;
		if((a[next_town].cost==-1)||(temp_cost < a[next_town].cost)) {
//cout << "cost update " << temp_cost << endl; 
			a[next_town].cost = temp_cost;
			for(auto titr = a[next_town].p.begin(); titr != a[next_town].p.end(); titr++ ) {
				que.insert(make_pair((*titr).first+temp_cost,(*titr).second));
//cout << "insert (cost,town) : " << (*titr).first+temp_cost << " " << (*titr).second << endl;
			}
		}
		//now_cost = temp_cost;
		que.erase(*itr);
	}
	//queue<long long> qu;
	//qu.push(r);
	/*while(!qu.empty()) {
		long long c = qu.front();
		long long now_cost = a[c].cost;
		qu.pop();
		for(auto itr = a[c].p.begin(); itr != a[c].p.end(); itr++) {
			if((a[*itr.second].cost == -1)||(a[*itr.second].cost > now_cost+*itr.first)) {
				a[*itr.second].cost = now_cost+*itr.first;
				qu.push(*itr.second);
			}
		}
	}*/
	for(i=0;i<v;i++) {
		if(a[i].cost == -1) cout << "INF\n";
		else cout << a[i].cost << endl;
	}
}

