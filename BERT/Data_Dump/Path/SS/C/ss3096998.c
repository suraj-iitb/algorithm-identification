# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

int V, E;
struct edge { LL to, cost; };
int start;
LL d[100100]; //距離
vector<edge> vec[100100];

void dijkstra() {
	for (int i = 0; i < 100100; i++)d[i] = HINF<LL>();
	priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
	d[start] = 0;
	pq.push(make_pair(d[start], start));//cost,to
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		int i = p.second;
		if (d[i] < p.first)continue;
		for (int k = 0; k < vec[i].size(); k++) {
			edge e = vec[i][k];
			if (d[e.to] <= d[i] + e.cost)continue;
			d[e.to] = d[i] + e.cost;
			pq.push(make_pair(d[e.to], e.to));
		}
	}
}

int main() {
	cin >> V >> E >> start;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		vec[a].push_back(edge{ b,c });
		//vec[b].push_back(edge{ a,c });
	}
	dijkstra();
	REP(i, V) {
		if (d[i] == HINF<LL>()) {
			cout << "INF" << endl;
		}
		else {
			cout << d[i] << endl;
		}
	}
}
