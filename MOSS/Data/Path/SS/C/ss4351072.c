#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct G
{
    int** vdmat;
    int v;
    int e;
    G(int a)
    {
        vdmat = new int* [a];
        for (int i = 0; i < a; i++)
            vdmat[i] = new int[a];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                vdmat[i][j] = 9999;
                if (i == j)
                {
                    vdmat[i][j] = 0;
                }
            }
        }
    }
};

struct Vtx
{
    int num;
    int d;
    Vtx(int a, int b)
    {
        num = a;
        d = b;
    }
};

bool operator < (const Vtx& a, const Vtx& b)
{
    return a.d > b.d;
}




int main()
{
    int v, v0;
    int e;
    cin >> v >> e >> v0;
    if (e < 10000)
    {
        G g(v);
        g.v = v;
        g.e = e;

        int h, t, w;
        for (int i = 0; i < g.e; i++)
        {
            cin >> h >> t >> w;
            g.vdmat[h][t] = w;
        }

        int* dist = new int[v];
        bool* visited = new bool[v];
        for (int i = 0; i < g.v; i++)
        {
            dist[i] = g.vdmat[v0][i];
            visited[i] = false;
            dist[v0] = 0;
        }

        visited[v0] = true;
        for (int i = 1; i < g.v; i++)
        {
            int min = 9999;
            int u = -1;
            for (int j = 0; j < g.v; j++)
            {
                if (visited[j] == false && dist[j] < min)
                {
                    min = dist[j];
                    u = j;
                }
            }
            if (u == -1)
                continue;
            visited[u] = true;
            for (int k = 0; k < g.v; k++)
            {
                if (visited[k] == false && g.vdmat[u][k] >= 0 && (min + g.vdmat[u][k]) < dist[k])
                {
                    dist[k] = min + g.vdmat[u][k];
                }
            }
        }

        for (int i = 0; i < g.v; i++)
        {
            if (dist[i] == 9999)
            {
                cout << "INF" << endl;
                continue;
            }
            cout << dist[i] << endl;
        }
    }
    else
    {
        int* gh = new int[e];
        int* gt = new int[e];
        int* gw = new int[e];
        int* index = new int[v];
        priority_queue<Vtx> q;
        for (int i = 0; i < v; i++)
            index[i] = -1;

        int h, t, w;
        int prev = -1;
        for (int i = 0; i < e; i++)
        {
            cin >> h >> t >> w;
            if (prev != h)
            {
                index[h] = i;
                prev = h;
            }
            gh[i] = h;
            gt[i] = t;
            gw[i] = w;
        }

        long int* dist = new long int[v];
        int loct;
        bool* visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            dist[i] = LONG_MAX;
            visited[i] = false;
            if (i == v0)
            {
                loct = index[v0];
            }
        }
        dist[v0] = 0;
        //visited[v0] = true;
        Vtx start(v0, dist[v0]);
        q.push(start);


        /*for (int i = loct; i < e; i++)
        {
            if (gh[i] != gh[loct])
                break;
            dist[gt[i]] = gw[i];
        }*/

        /*for (int i = 0; i < v; i++)
        {
            long int min = LONG_MAX;
            int u = -1;
            for (int j = 0; j < v; j++)
            {
                if (visited[j] == false && dist[j] < min)
                {
                    min = dist[j];
                    u = j;
                }
            }
            if (u == -1)
                continue;
            visited[u] = true;
            loct = index[u];
            for (int k = 0; k < v; k++)
            {
                if (loct == -1)
                    break;
                if (visited[k] == false)
                {
                    for (int d = loct; d < e; d++)
                    {
                        if (gh[d] != gh[loct])
                            break;
                        if ((gw[d] + min) < dist[gt[d]] && gw[d] >= 0)
                            dist[gt[d]] = min + gw[d];
                    }
                }
            }
        }*/
        while (!q.empty())
        {
            int u = q.top().num;
            q.pop();
            if (visited[u])
                continue;
            else
                visited[u] = true;
            loct = index[u];
            for (int k = loct; k < e; k++)
            {
                if (loct == -1 || gh[k] != gh[loct])
                    break;
                if (!visited[gt[k]] && (dist[u] + gw[k]) < dist[gt[k]])
                {
                    dist[gt[k]] = dist[u] + gw[k];
                    Vtx n(gt[k], dist[gt[k]]);
                    q.push(n);
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            if (dist[i] == LONG_MAX)
            {
                cout << "INF" << endl;
                continue;
            }
            cout << dist[i] << endl;
        }
     }
    return 0;
}


