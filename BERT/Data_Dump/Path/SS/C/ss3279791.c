#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

typedef tuple<int, int> tu;

struct smaller {
	bool operator()(tu a, tu b) {
		if (get<0>(a) == get<0>(b)) return get<1>(a)>get<1>(b);
		return get<0>(a)>get<0>(b);
	}
};

int V, E, r, s, t, d;

set<int> S; //最短距離が確定した頂点の集合
priority_queue<tu, vector<tu>, smaller> Q;
const int inf = 1000000000;

int main()
{
	ios::sync_with_stdio(false);
	cin >> V >> E >> r;
	vector<int> l(V, inf); //length
	vector<priority_queue<tu, vector<tu>, smaller>> e(V); //edge
	l[r] = 0;
	Q.push(make_tuple(0, r));
	S.insert(r);

	for (int i = 0; i<E; i++)
	{
		cin >> s >> t >> d;
		e[s].push(make_tuple(d, t));
	}

	while (!Q.empty())
	{
		while (!e[r].empty())
		{
			t = get<1>(e[r].top());
			if (S.count(t) == 1)
			{
				e[r].pop();
				continue;
			}
			d = get<0>(e[r].top());
			d += l[r];
			e[r].pop();
			Q.push(make_tuple(d, t));
		}
		while (!Q.empty())
		{
			t = get<1>(Q.top());
			if (S.count(t) == 1)
			{
				Q.pop();
			}
			else
			{
				d = get<0>(Q.top());
				l[t] = d;
				S.insert(t);
				break;
			}
		}
		r = t;
	}

	for (int i = 0; i<V; i++)
	{
		if (l[i] == inf)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << l[i] << endl;
		}
	}
	return 0;
}

