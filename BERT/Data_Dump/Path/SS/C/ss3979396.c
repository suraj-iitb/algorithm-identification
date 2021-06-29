#include "bits/stdc++.h"
using namespace std;

template<typename Type>
vector<Type> Dijkstra(vector<vector<pair<long long, Type> > > Graph, long long Start) {
	using PT = pair<Type, long long>;
	const Type Inf = numeric_limits<Type>::max();
	long long Size = Graph.size();
	vector<Type> Dist;
	Dist.assign(Size, Inf);
	priority_queue<PT, vector<PT>, greater<PT> > PQ;

	Dist[Start] = 0;
	PQ.emplace(PT(Dist[Start], Start));
	while (!PQ.empty()) {
		PT p = PQ.top();
		PQ.pop();
		Type D = p.first;
		long long E = p.second;
		if (Dist[E] < D) continue;
		for (pair<long long, Type> Next : Graph[E]) {
			Type ND = Next.second;
			long long NE = Next.first;
			if (Dist[NE] > Dist[E] + ND) {
				Dist[NE] = Dist[E] + ND;
				PQ.emplace(PT(Dist[NE], NE));
			}
		}
	}
	return Dist;
}

int main() {
	long long N, M, R;
	vector<vector<pair<long long, long long> > > V;
	cin >> N >> M >> R;
	V.resize(N);
	for (int i = 0; i < M; i++) {
		long long S, T, C;
		cin >> S >> T >> C;
		V[S].push_back({ T, C });
	}
	vector<long long> ANS = Dijkstra<long long>(V, R);
	for (int i = 0; i < N; i++) {
		if (ANS[i] == LLONG_MAX) cout << "INF" << endl;
		else cout << ANS[i] << endl;
	}
}
