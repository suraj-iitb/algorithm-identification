

	



#include <bits/stdc++.h>
using namespace std;

int main()
{

	int v,e,r;
	cin >> v >> e >> r;

	vector<map<int,int>> g(v);
	for (int i=0;i<e;++i)
	{
		int s,t,d;
		cin >> s >> t >> d;
		g[s][t]=d;
		//g[t][s]=d;
	}

	vector<int> d(v);
	const int infinity=65536*32766;
	for (int i=0;i<v;++i)
	{
		d[i]=infinity;
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0,r));

	while (pq.size()>0)
	{
		pair<int,int> p=pq.top();
		pq.pop();
		if (d[p.second]==infinity)
		{
			d[p.second]=p.first;
			for (pair<int,int> pp: g[p.second])
			{
				pq.push(make_pair(p.first+pp.second,pp.first));
			}
		}
	}

	for (int i=0;i<v;++i)
	{
		if (d[i]!=infinity)
		{
			cout << d[i] << endl;
		}
		else
		{
			cout << "INF" << endl;
		}
	}
}

	




