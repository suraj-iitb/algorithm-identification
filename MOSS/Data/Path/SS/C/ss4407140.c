#include <bits/stdc++.h>

//{ START
using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (a); i > (n); --i)
#define arep(i, x) for (auto &&i : (x))
#define irep(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
//降順はgreater<T>()
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
//gcd lcmはそのままok
#define gcd(a, b) __gcd(a, b)
#define bits(n) (1 << (n))
#define pcnt(x) __builitin_popcountll(x)
//配列内等要素削除
#define unique(x) (x).erase(unique(x).begin(),(x).end()),(x).end());
#define Fixed(n) fixed << setprecision(n)
//総和
#define sowa(n) ((n) * ((n) + 1)) / 2
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).flont_back(a)
#define eb(x, a) (x).emplaes_back(a)
#define F first
#define S second
#define cauto (const auto &)
template <class A, class B>
using pii = vector<pair<A, B>>;
template <class T> //昇順
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> //降順
using max_heap = priority_queue<T>;
template <class A, class B>
using umap = unordered_map<A, B>;
template <class A>
using uset = unordered_set<A>;
template <class T>
bool chmax(T &a, const T &b) //最大値更新 返り値はbool
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) //最小値更新 返り値はbool
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr long long mod1 = 1e9 + 7;
constexpr long long mod2 = 998244353;
//} END
using P = pair<int, int>; //firstは最短距離,secondは頂点の番号

vector<vector<P>> graph;
vector<int> min_cost;

void Dijkstra(int s)
{
    //昇順でfirstを小さい方から取る
    priority_queue<P, vector<P>, greater<P>> que;
    min_cost[s] = 0;
    que.emplace(0, s);

    while (!que.empty())
    {
        int now_cost, now_node;
        tie(now_cost, now_node) = que.top();
        que.pop();

        if (min_cost[now_node] < now_cost) //queの値より新しいcostの方が小さいとき見ない
        {
            continue;
        }

        for (int i = 0; i < graph[now_node].size(); ++i)
        {
            int next_node, next_cost;
            tie(next_node, next_cost) = graph[now_node][i];

            if (chmin(min_cost[next_node], min_cost[now_node] + next_cost)) //最短経路の更新
            {
                que.emplace(min_cost[next_node], next_node);
            }
        }
    }
}

signed main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int V, E, r;
    cin >> V >> E >> r;

    min_cost.resize(V + 1, INF);
    graph.resize(V + 1);

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); //グラフの構築
        //graph[b].emplace_back(a, c);
    }

    Dijkstra(r);

    rep(i, 0, V)
    {
        if (min_cost[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << min_cost[i] << '\n';
        }
    }

    return 0;
}
