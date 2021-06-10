#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<typename T> // key
struct RadixHeap{
	vector<pair<int, T>> v[31]; //max<2^30
	int last;
	int size;
	inline int bsr(int x){
		if(x==0) return -1;
		else return 31-__builtin_clz(x);
	}
	RadixHeap():last(0), size(0){}
	bool empty(){
		return size==0;
	}
	void push(int val, T key){
		size++;
		v[bsr(val^last)+1].push_back({val, key});
	}
	pair<int, T> pop(){
		size--;
		if(!v[0].empty()){
			auto ret=v[0].back();
			v[0].pop_back();
			return ret;
		}
		int k=1;
		while(v[k].empty()) k++;
		int minval=v[k][0].first;
		T minkey=v[k][0].second;
		for(auto p:v[k]){
			if(p.first<minval){
				minval=p.first;
				minkey=p.second;
			}
		}
		last=minval;
		bool myon=1;
		for(auto p:v[k]){
			if(myon && p.first==minval && p.second==minkey){
				myon=0;
				continue;
			}
			v[bsr(p.first^last)+1].push_back(p);
		}
		v[k].clear();
		return make_pair(minval, minkey);
	}
};
int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	vector<vector<P>> g(n);
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, c});
	}
	const int INF=1e9+7;
	RadixHeap<int> que;
	vector<int> d(n, INF);
	d[s]=0;
	que.push(0, s);
	while(!que.empty()){
		auto p=que.pop();
		int x=p.second;
		if(d[x]<p.first) continue;
		for(auto q:g[x]){
			int y=q.first;
			if(d[y]>d[x]+q.second){
				d[y]=d[x]+q.second;
				que.push(d[y], y);
			}
		}
	}
	for(int i=0; i<n; i++){
		if(d[i]==INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
	return 0;
}
