#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define INF 1000000000
struct Edge{
	int to;
	int weight;
};
void dijkstra(vector<vector<Edge>> &G,vector<int> &distance,int start)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		pair<int,int> p = pq.top();
		pq.pop();
		if(p.first > distance[p.second])
		{continue;}
		distance[p.second] = p.first;
		for(auto e : G[p.second])
		{
			if(distance[e.to] <= distance[p.second] + e.weight)
			{continue;}
			pq.push({distance[p.second] + e.weight,e.to});
		}
	}
}
int main()
{
	int Vnum,Enum,start;
	cin >> Vnum >> Enum >> start;
	int i;
	vector<vector<Edge>> G;
	G.resize(Vnum);
	for(i = 0;i < Enum;i++)
	{
		Edge tmpedge;
		int tmps;
		cin >> tmps >> tmpedge.to >> tmpedge.weight;
		G[tmps].push_back(tmpedge);
	}
	vector<int> distance;
	distance.assign(Vnum,INF);
	dijkstra(G,distance,start);
	for(i = 0;i < Vnum;i++)
	{
		if(distance[i] != INF)
		cout << distance[i] << endl;
		else
		cout << "INF" << endl;
	}
	return 0;
}
		
		
		
	
	
