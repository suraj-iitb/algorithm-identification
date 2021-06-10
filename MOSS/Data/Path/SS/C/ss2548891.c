#include "limits.h"
#include <cstring>
#include <iostream>
using namespace std;
#define Maxvernum 100000
#define Maxarcnum 500000
typedef struct arcs
{
	int start;
	int to;
	int cost;
};
arcs input[Maxarcnum];
int dist[Maxvernum];
int visited[Maxvernum];
int V, E, r;
void BellmanFord(int r)
{
	while(1)
	{
		int flag = 0;
		for (int i=0; i<E; i++)
		{
			if (dist[input[i].start] != INT_MAX && dist[input[i].start] + input[i].cost < dist[input[i].to])
			{
				dist[input[i].to] = dist[input[i].start] + input[i].cost;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int main()
{
	cin>>V>>E>>r;
	for (int i=0; i<Maxvernum; i++)
		dist[i] = INT_MAX;
	memset(visited, 0, sizeof(visited));
	for (int i=0; i<E; i++)
	{
		cin>>input[i].start>>input[i].to>>input[i].cost;
		if (input[i].start == r)
			dist[input[i].to] = input[i].cost;
	}
	dist[r] = 0;
	visited[r] = 1;
	BellmanFord(r);
	for (int i=0; i<V; i++)
		if (dist[i] != INT_MAX)
			cout<<dist[i]<<endl;
		else
			cout<<"INF"<<endl;
	return 0;
}
