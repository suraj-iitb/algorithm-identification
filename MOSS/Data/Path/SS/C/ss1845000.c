#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>

typedef vector<pair<int, int> > adj;

struct current_cost
{
    int index, cost;
    bool operator < (const current_cost &cur) const
    {
        return cost > cur.cost;
    }
};

current_cost init(int i, int c)
{
    current_cost cur;
    cur.index = i, cur.cost = c;
    return cur;
}

int main()
{
    int i, j, k, n, m, r, next, cost;
    scanf("%d %d %d", &n, &m, &r);
    adj *adlist;
    adlist = new adj [n];

	for(int k = 0; k < m; k++){
		scanf("%d %d %d", &j, &next, &cost);
		adlist[j].push_back(make_pair(next, cost));
	}

    int *d;
    d = new int [n];
    for(i = 0; i < n; i++){ d[i] = -1; }
	d[r] = 0;

    priority_queue<current_cost> C;
    current_cost cur = init(r, 0);
    C.push(cur);

    int size;
    bool *check;
    check = new bool [n];
    for(i = 0; i < n; i++){ check[i] = false; }

    while(!C.empty())
    {
        cur = C.top(); C.pop();
		i = cur.index;
        if(check[i]) continue;
        check[i] = true;
 
        size = adlist[i].size();
        for(int j = 0; j < size; j++){
            int k = adlist[i][j].first;
            if(d[k] < 0 || d[i] + adlist[i][j].second < d[k]){
                d[k] = d[i] + adlist[i][j].second;
                C.push(init(k, d[k]));
            }
        }
    };
    for(i = 0; i < n; i++){
		(check[i] ? printf("%d\n", d[i]) : printf("INF\n"));
	}
    return 0;
}
