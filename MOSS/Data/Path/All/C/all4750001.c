#pragma region Macro
#pragma region Basic
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; i++)
#define FORD(i, a, b) for (int i = (a), i##_len = (b); i > i##_len; i--)
#define FORR(t, a) for (auto t : a)
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#define GET(i, j) get<j>(i)
#define MT(x, ...) make_tuple(x, __VA_ARGS__)
#define SZ(x) ((int)(x).size())
//#define ZERO(x) memset(x, 0, sizeof(x))
//#define FILL(x, y) memset(x, y, sizeof(x))
#define UNUSED(x) (void(x));
#define PB push_back
#define EB emplace_back
#ifdef _DEBUG
#define PRE_COMMAND             \
    std::cin.rdbuf(in.rdbuf()); \
    cout << fixed << setprecision(15);
#else
#define PRE_COMMAND cout << fixed << setprecision(15);
#endif
const double EPS = 1e-10;
const double PI = acos(-1.0);
template <class T>
auto MAX(T& seq) {
    return *max_element(seq.begin(), seq.end());
}
template <class T>
auto MIN(T& seq) {
    return *min_element(seq.begin(), seq.end());
}
template <class T>
auto SUM(T& seq) {
    T temp{0};
    auto& temp2 = temp[0];
    return accumulate(seq.begin(), seq.end(), temp2);
}
template <class T>
void SORT(T& seq) {
    sort(seq.begin(), seq.end());
}
template <class T, class S>
void SORT(T& seq, S& sort_order) {
    sort(seq.begin(), seq.end(), sort_order);
}
template <class T>
void SORTR(vector<T>& seq) {
    sort(seq.begin(), seq.end(), greater<T>());
}
template <class T>
void CHMAX(T& a, const T& b) {
    if (a < b) { a = b; }
}
template <class T>
void CHMIN(T& a, const T& b) {
    if (b < a) { a = b; }
}
template <class T>
set<T> VECTOR_2_SET(vector<T>& v) {
    set<T> s;
    for (auto ele : v) { s.insert(ele); }
    return s;
}
template <class T>
vector<T> SET_2_VECTOR(set<T>& s) {
    vector<T> v;
    for (auto ele : s) { v.push_back(ele); }
    return v;
}
#pragma endregion Basic
#pragma region overload
template <class T, class S>
void operator+=(vector<T>& l, S& r) {
    for (auto i : r) { l.push_back(i); }
}
template <class T, class S>
void operator+=(set<T>& l, S& r) {
    for (auto i : r) { l.insert(i); }
}
template <class T, class S>
void operator+=(multiset<T>& l, S& r) {
    for (auto i : r) { l.insert(i); }
}
template <class T, class S>
vector<T> operator+(vector<T>& l, S& r) {
    vector<T> l_copy = l;
    for (auto i : r) { l_copy.push_back(i); }
    return l_copy;
}
template <class T>
vector<T> operator+(const vector<T> l, const vector<T>& r) {
    vector<T> l_copy = l;
    for (auto i : r) { l_copy.push_back(i); }
    return l_copy;
}
template <class T, class S>
set<T> operator+(set<T>& l, S& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T>
set<T> operator+(const set<T> l, const set<T>& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T, class S>
multiset<T> operator+(multiset<T>& l, S& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T>
multiset<T> operator+(const multiset<T> l, const set<T>& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
string operator+(const string l, const string& r) {
    string str = l;
    str += r;
    return str;
}
string operator*(const string l, const size_t& r) {
    string str = l;
    for (size_t i = 0; i < r; i++) { str += l; }
    return str;
}
#pragma endregion overload
#pragma region Input
template <class Head>
void INPUT(vector<Head>& head);
template <size_t N, class Head>
void INPUT(array<Head, N>& head);
template <class T1>
void INPUT(tuple<T1>& t);
template <class T1, class T2>
void INPUT(tuple<T1, T2>& t);
template <class T1, class T2, class T3>
void INPUT(tuple<T1, T2, T3>& t);
template <class T1, class T2, class T3, class T4>
void INPUT(tuple<T1, T2, T3, T4>& t);
template <class T1, class T2, class T3, class T4, class T5>
void INPUT(tuple<T1, T2, T3, T4, T5>& t);
template <class Head>
void INPUT(Head& head);
template <class Head, class... Tail>
void INPUT(Head& head, Tail&... tail);
//本体
template <class Head>
void INPUT(vector<Head>& head) {
    for (size_t i = 0; i < head.size(); i++) { INPUT(head[i]); }
}
template <size_t N, class Head>
void INPUT(array<Head, N>& head) {
    for (size_t i = 0; i < head.size(); i++) { INPUT(head[i]); }
}
template <class T1>
void INPUT(tuple<T1>& t) {
    cin >> get<0>(t);
}
template <class T1, class T2>
void INPUT(tuple<T1, T2>& t) {
    cin >> get<0>(t) >> get<1>(t);
}
template <class T1, class T2, class T3>
void INPUT(tuple<T1, T2, T3>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
}
template <class T1, class T2, class T3, class T4>
void INPUT(tuple<T1, T2, T3, T4>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
}
template <class T1, class T2, class T3, class T4, class T5>
void INPUT(tuple<T1, T2, T3, T4, T5>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
}
template <class Head>
void INPUT(Head& head) {
    cin >> head;
}
template <class Head, class... Tail>
void INPUT(Head& head, Tail&... tail) {
    INPUT(head);
    INPUT((tail)...);
}
#pragma endregion Input
#pragma region Print
template <class T1>
void PRINT2(tuple<T1> t);
template <class T1, class T2>
void PRINT2(tuple<T1, T2> t);
template <class T1, class T2, class T3>
void PRINT2(tuple<T1, T2, T3> t);
template <class T1, class T2, class T3, class T4>
void PRINT2(tuple<T1, T2, T3, T4> t);
template <class T1, class T2, class T3, class T4, class T5>
void PRINT2(tuple<T1, T2, T3, T4, T5> t);
template <class Head>
void PRINT2(vector<Head> head);
template <class Head>
void PRINT2(vector<vector<Head>> head);
template <size_t N, class Head>
void PRINT2(vector<array<Head, N>> head);
template <class... Head>
void PRINT2(vector<tuple<Head...>> head);
template <size_t N, class Head>
void PRINT2(array<Head, N> head);
template <class Head>
void PRINT2(Head head);
template <class Head, class... Tail>
void PRINT2(Head head, Tail... tail);
template <class Head>
void PRINT(Head head);
template <class... Head>
void PRINT(Head... head);
template <int N, class Head>
void PRINT(Head head);
template <class T1>
void PRINT2(tuple<T1> t) {
    PRINT2(get<0>(t));
}
template <class T1, class T2>
void PRINT2(tuple<T1, T2> t) {
    PRINT2(get<0>(t), get<1>(t));
}
template <class T1, class T2, class T3>
void PRINT2(tuple<T1, T2, T3> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t));
}
template <class T1, class T2, class T3, class T4>
void PRINT2(tuple<T1, T2, T3, T4> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t), get<3>(t));
}
template <class T1, class T2, class T3, class T4, class T5>
void PRINT2(tuple<T1, T2, T3, T4, T5> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t), get<3>(t), get<4>(t));
}
template <class Head>
void PRINT2(vector<Head> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << " "; }
    }
}
template <class Head>
void PRINT2(vector<vector<Head>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <size_t N, class Head>
void PRINT2(vector<array<Head, N>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <class... Head>
void PRINT2(vector<tuple<Head...>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <size_t N, class Head>
void PRINT2(array<Head, N> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << " "; }
    }
}
template <class Head>
void PRINT2(Head head) {
    cout << head;
}
template <class Head, class... Tail>
void PRINT2(Head head, Tail... tail) {
    PRINT2(head);
    cout << " ";
    PRINT2((tail)...);
}
template <class Head>
void PRINT(Head head) {
    PRINT2(head);
    cout << endl;
}
template <class... Head>
void PRINT(Head... head) {
    PRINT2((head)...);
    cout << endl;
}
template <int N, class Head>
void PRINT(Head head) {
    PRINT2(head);
    cout << endl;
}
#pragma endregion Print
#pragma endregion Macro

template <class T>
vector<T> dijkstra(vector<vector<tuple<int, T>>> g, int start) {
    T inf = numeric_limits<T>::max() / 3;
    vector<T> dist((int)g.size(), inf);
    priority_queue<tuple<T, int>, vector<tuple<T, int>>, greater<tuple<T, int>>>
        pri;
    pri.push(make_tuple(0, start));
    while (pri.size() != 0) {
        T d;
        int idx;
        tie(d, idx) = pri.top();
        pri.pop();
        if (dist[idx] == inf) {
            dist[idx] = d;
            for (tuple<int, T> temp : g[idx]) {
                int j;
                T d2;
                tie(j, d2) = temp;
                if (dist[j] == inf) { pri.push(make_tuple(d + d2, j)); }
            }
        }
    }
    return dist;
}

// グラフ、無限大、スタート、（ゴール）の設定
template <class T>
vector<T> bellman_ford(vector<vector<tuple<int, T>>>& g_pre, T inf, int start,
                       int goal = -1) {
    // 前処理
    int n = (int)g_pre.size();
    vector<vector<tuple<int, T>>> g(n, vector<tuple<int, T>>(0));
    int now, next;
    T value;
    vector<int> stack({start});
    vector<bool> visited(n, false);
    visited[start] = true;
    while (stack.size()) {
        now = stack.back();
        stack.pop_back();
        for (tuple<int, T> temp : g_pre[now]) {
            next = get<0>(temp);
            if (visited[next] == false) {
                visited[next] = true;
                stack.push_back(next);
            }
            g[now].push_back(temp);
        }
    }
    if (goal != -1) {
        vector<vector<tuple<int, T>>> g_rev(n, vector<tuple<int, T>>(0));
        for (int i = 0; i < n; i++) {
            for (tuple<int, T> temp : g[i]) {
                tie(next, value) = temp;
                g_rev[next].push_back(make_tuple(i, value));
            }
        }
        stack = {goal};
        g.assign(n, vector<tuple<int, T>>(0));
        visited.assign(n, false);
        visited[goal] = true;
        while (stack.size()) {
            now = stack.back();
            stack.pop_back();
            for (tuple<int, T> temp : g_rev[now]) {
                tie(next, value) = temp;
                if (visited[next] == false) {
                    visited[next] = true;
                    stack.push_back(next);
                }
                g[next].push_back(make_tuple(now, value));
            }
        }
    }
    // n回緩和させる
    vector<T> dist(n, inf), dist2;
    dist[start] = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        dist2 = dist;
        for (int i = 0; i < n; i++) {
            if (dist[i] != inf) {
                for (tuple<int, T> temp : g[i]) {
                    tie(next, value) = temp;
                    dist[next] = min(dist[next], dist[i] + value);
                }
            }
        }
    }
    // n-1回目とn回目の結果が一致していればdistを返す、そうでなければ空のvectorを返す
    if (dist == dist2) {
        if (goal == -1) {
            return dist;
        } else {
            return {dist[goal]};
        }
    } else {
        return {};
    }
}

int main() {
    PRE_COMMAND
    int n, m;
    INPUT(n, m);
    int x, y;
    ll z, inf = pow(10, 10);
    vector<vector<tuple<int, ll>>> g(n, vector<tuple<int, ll>>(0));
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[x].push_back(make_tuple(y, z));
        dist[x][y] = z;
    }
    REP(i, n) {
        if (bellman_ford(g, inf, (int)0).size() == 0) {
            PRINT("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) { dist[i][i] = 0; }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf) {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }
    REP(i, n) {
        REP(j, n) {
            if (dist[i][j] == inf) {
                cout << "INF";
            } else {
                cout << dist[i][j];
            }
            if (j < n - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}
