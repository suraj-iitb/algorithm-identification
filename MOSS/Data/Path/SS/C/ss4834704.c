#include<bits/stdc++.h>
using namespace std;
class Graph {
public:
    int node;
    list<pair<int,int> > *adj;
    int *parent;
    int *cost;
    Graph(int node)
    {
        this->node= node;
        adj = new list<pair<int,int> > [node+1];
        parent = new int[node+1];
        cost = new int[node+1];

        for(int i=0;i<=node;i++)
        {
            cost[i]=INT_MAX;
        }
    }
    void addedge(int u,int v,int cost)
    {
        adj[u].push_back(make_pair(v,cost));
    }
    void dijkstra(int source)
    {
         priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
        cost[source]=0;
        parent[source]=source;

        q.push(make_pair(cost[source],source));

        while(!q.empty())
        {
            int parentnode = q.top().second;
            q.pop();
            list<pair<int,int> >:: iterator it;
            for(it=adj[parentnode].begin();it!=adj[parentnode].end();it++)
            {
                int currentnode=it->first;
                int currentcost=it->second;
                if(cost[parentnode]+currentcost < cost[currentnode])
                {
                    cost[currentnode] = cost[parentnode]+currentcost;
                    parent[currentnode]=parentnode;
                    q.push(make_pair(cost[currentnode],currentnode));
                }
            }
        }

    }
    void printcost()
    {
        for(int i=0;i<node;i++)
        {
            if(cost[i]<INT_MAX)
            {
                cout<<cost[i]<<endl;
            }
            else
            {
                cout<<"INF"<<endl;
            }
        }
    }

};
int main()
{

    int node,edge,source;
    cin>>node>>edge>>source;
    int u,v,cost;
    Graph graph(node);
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>cost;
        graph.addedge(u,v,cost);
    }
    graph.dijkstra(source);
    graph.printcost();

}
