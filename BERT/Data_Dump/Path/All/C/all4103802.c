#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rs64() {
	int64_t n;
	scanf("%" SCNd64, &n);
	return n;
}


#define INF (10000000000LL)
int main() {
	int n = ri(), m = ri();
	std::vector<std::pair<int, int64_t> > hen[n];
	for (int i = 0; i < m; i++) {
		int x = ri();
		int y = ri();
		int cost = ri();
		hen[x].push_back({y, cost});
	}
	
	auto bf = [&] (int start) {
		std::vector<int64_t> dist(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				for (auto k : hen[j]) if (dist[k.first] > dist[j] + k.second) {
					if (i == n - 1) return std::vector<int64_t>();
					dist[k.first] = dist[j] + k.second;
				}
		}
		return dist;
	};
	auto solve = [&] () {
		std::vector<std::vector<int64_t> > res(n, std::vector<int64_t>(n, INF));
		auto pot = bf(0);
		if (!pot.size()) return std::vector<std::vector<int64_t> >();
		for (int i = 0; i < n; i++) for (auto &j : hen[i]) j.second += pot[i] - pot[j.first];
		for (int i = 0; i < n; i++) {
			using T = std::pair<int64_t, int>;
			std::priority_queue<T, std::vector<T>, std::greater<T> > que;
			que.push({res[i][i] = 0, i});
			while (que.size()) {
				auto cur = que.top();
				que.pop();
				if (cur.first != res[i][cur.second]) continue;
				for (auto j : hen[cur.second]) {
					if (res[i][j.first] > cur.first + j.second) {
						res[i][j.first] = cur.first + j.second;
						que.push({res[i][j.first], j.first});
					}
				}
			}
			for (int j = 0; j < n; j++) {
				res[i][j] -= pot[i] - pot[j];
				if (res[i][j] > INF / 2) res[i][j] = INF;
			}
		}
		return res;
	};
	auto cor = solve();
	
	if (!cor.size()) {
		std::cout << "NEGATIVE CYCLE" << std::endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j) printf(" ");
			if (cor[i][j] == INF) printf("INF");
			else printf("%lld", (long long) cor[i][j]);
		}
		puts("");
	}
	
	return 0;
}

