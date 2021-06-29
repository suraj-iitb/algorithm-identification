#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <queue>

#define INF 2147483647

using namespace std;

struct edge { int to,cost;};	
typedef pair<int,int> P;

int main(){
	int V,E,r,
	    s,t,d,
	    score[100000];
	P p;
	edge e;
	vector<edge> G[100000];
	priority_queue<P,vector<P>,greater<P> > q;
	
	scanf("%d %d %d",&V,&E,&r);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&s,&t,&d);
		G[s].push_back( {t,d} );
	}
	
	fill(score , score + V , INF);
	score[r] = 0;
	q.push( P(0,r) );
	
	while(!q.empty()){
		p = q.top();
		q.pop();
		r = p.second;
		if(score[r] < p.first) continue;
		for(int j=0;j<G[r].size();j++){
			e = G[r][j];
			if(score[e.to] > score[r]+e.cost){
				score[e.to] = score[r]+e.cost;
				q.push( P(score[e.to],e.to) );
			}
		}
	}
	for(int i=0;i<V;i++){
		if(score[i]==2147483647) printf("INF\n");
		else printf("%d\n",score[i]);
	}
		
	return 0;
}
