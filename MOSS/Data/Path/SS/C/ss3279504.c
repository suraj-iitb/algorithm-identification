#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <limits>
#define dis(a) get<0>(a)
#define index(a) get<1>(a)
#define min(a,b) a<b?a:b
#define INF numeric_limits<int>::max()
using namespace std;
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> ver_unconfirmed; //distance,index
int ver_n, edge_n, dep_i;
vector<int> dis, dis_u;
vector<vector<tuple<int, int>>> conn_list; //sep;dest,cost
void dijkstra()
{
	ver_unconfirmed.push(make_tuple(0, dep_i)); //distance,index
	dis_u[dep_i] = 0;
	while (!ver_unconfirmed.empty())
	{
		auto ver_nearest = ver_unconfirmed.top();
		if (dis[index(ver_nearest)] == INF)
		{
			dis[index(ver_nearest)] = dis(ver_nearest);
			ver_unconfirmed.pop();
			for (auto vertex : conn_list[index(ver_nearest)])
			{
				if (dis[get<0>(vertex)] == INF)
				{
					dis_u[get<0>(vertex)] = min(dis_u[get<0>(vertex)], dis[index(ver_nearest)] + get<1>(vertex));
					ver_unconfirmed.push(make_tuple(dis_u[get<0>(vertex)], get<0>(vertex)));
				}
			}
		}
		else
		{
			ver_unconfirmed.pop();
		}
	}
}

int main()
{
	scanf("%d%d%d", &ver_n, &edge_n, &dep_i);
	conn_list = vector<vector<tuple<int, int>>>(ver_n, vector<tuple<int, int>>());
	for (int i = 0; i < edge_n; i++)
	{
		int start, end, cost;
		scanf("%d%d%d", &start, &end, &cost);
		conn_list[start].push_back(make_tuple(end, cost));
	}
	dis_u = dis = vector<int>(ver_n, INF);
	dijkstra();
	for (int i : dis)
	{
		if (i != INF)
		{
			printf("%d\n", i);
		}
		else
		{
			printf("INF\n");
		}
	}
}
