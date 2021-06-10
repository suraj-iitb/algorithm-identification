#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include<bits/stdc++.h>

using namespace std;

// #include "../../datastructure/FibHeap.cpp"
template<class Key, class Compare = less<Key>>
struct FibHeap {
	struct node; using np = node*;
	using u32 = uint_fast32_t;
	struct node {
		Key key;
		np left, right;
		np par, child;
		u32 degree;
		bool mark;
		node(Key k) : key(k), left(this), right(this), par(nullptr), child(nullptr), degree(0), mark(false) {}
		node() : key(), left(this), right(this), par(nullptr), child(nullptr), degree(0), mark(false) {}
	};
	np maximum;
	np roots;
	u32 n;
	FibHeap() : maximum(nullptr), n(0) {
		roots = new node();
	}
	np push(Key k) {
		n++;
		np x = new node(move(k));
		insert_node_to_roots(x);
		// if (!maximum) return maximum = x;
		if (!maximum) maximum = x;
		update_maximum(x);
		return x;
	}
	np pop() {
		np z = maximum;
		if (z) {
			for (np x : make_list_vector(z->child)) {
				insert_node_to_roots(x);
			}
			cut_par(z); cut_list_sub(z);
			if (roots == roots->right) maximum = nullptr;
			else {
				Consolidate();
			}
			n--;
		}
		return z;
	}
	const Key& top() const {
		return maximum->key;
	}
	void check() const {
		bool f = roots == roots->right;
		for (np x : make_roots_vector()) {
			assert(!x->par);
			f = f || x == maximum;
		}
		assert(f);
		check_dfs(roots);
	}
	u32 size() const {return n;}
	void decrease_key(np x, Key k) {
		if (!Compare()(x->key, k)) return;
		x->key = move(k);
		np y = x->par;
		if (y && Compare()(y->key, x->key)) {
			cut(x, y);
			cascading_cut(y);
		}
	}
	bool empty() const {
		return n == 0;
	}
private:
	void cut(np child, np par) {
		par->degree--;
		if (par->child == child) {
			if (child->right == child) par->child = nullptr;
			else par->child = child->right;
		}
		cut_list(child);
		insert_node_to_roots(child);
		child->mark = false;
	}
	void cascading_cut(np x) {
		if (np z = x->par) {
			if (x->mark) {
				cut(x, z);
				cascading_cut(z);
			}
			else x->mark = true;
		}
	}
	int check_dfs(np n) const {
		if (!n) return 0;
		vector<np> ls = make_list_vector(n);
		int d = ls.size();
		for (auto x : ls) {
			assert(x->left->right == x);
			assert(x->degree == u32(check_dfs(x->child)));
			if (x->child) assert(x->child->par == x);
		}
		return d;
	}
	inline void cut_par(np x) {
		if (!x->par) return;
		x->par->degree--;
		if (x->par->child == x) {
			if (x->right == x) x->par->child = nullptr;
			else x->par->child = x->right;
		}
	}
	inline void insert_node_to_roots(np x) {
		// assert(x);
		x->par = nullptr;
		x->left = roots;
		x->right = roots->right;
		roots->right = roots->right->left = x;
	}
	inline void insert_node_to_list(np& list, np n) {
		if (!list) list = n->left = n->right = n;
		else {
			n->left = list;
			n->right = list->right;
			list->right = list->right->left = n;
		}
	}
	inline void update_maximum(np x) {
		// assert(x && maximum);
		if (Compare()(maximum->key, x->key)) maximum = x;
	}
	inline void cut_list(np x) {
		cut_list_sub(x);
		x->left = x->right = x;
	}
	inline void cut_list_sub(np x) {
		x->left->right = x->right;
		x->right->left = x->left;
	}
	inline vector<np> make_list_vector(np n) const {
		if (!n) return move(vector<np>(0));
		vector<np> res(1, n);
		for (np nn = n->right; nn != n; nn = nn->right) {
			res.push_back(nn);
		}
		return move(res);
	}
	inline vector<np> make_roots_vector() const {
		vector<np> res;
		for (np n = roots->right; n != roots; n = n->right) {
			res.push_back(n);
		}
		return move(res);
	}
	inline void Consolidate() {
		constexpr double phi = (1 + sqrt(5)) / 2;
		int sz = 2;
		for (double p = phi; p < n; p *= phi, sz++);
		vector<np> A(sz, nullptr);
		// assert(!maximum->par);
		for (np x : make_roots_vector()) {
			u32 d = x->degree;
			while (np y = A[d]) {
				if (Compare()(x->key, y->key)) swap(x, y);
				Link(y, x);
				A[d] = nullptr;
				d++;
			}
			A[d] = x;
		}
		maximum = roots->right;
		for (np x = roots->right->right; x != roots; x = x->right) update_maximum(x);
	}
	inline void Link(np child, np par) {
		// assert(child != par);
		// assert(!child->par);
		// assert(!par->par);
		cut_list_sub(child);
		insert_node_to_list(par->child, child);
		child->par = par;
		par->degree++;
		child->mark = false;
	}
};

namespace dijkstra_n {
template<class W>
struct Edge {
	using type = Edge<W>;
	int to;
	W w;
	template<class... Args> Edge(int t, Args... args) : to(t), w(args...) {}
	inline bool operator<(const Edge& rhs) const { return w < rhs.w; }
	inline bool operator>(const type& rhs) const { return rhs < *this; }
	inline bool operator>=(const type& rhs) const { return !(*this < rhs); }
	inline bool operator<=(const type& rhs) const { return !(rhs < *this); }
	inline bool operator==(const type& rhs) const { return !(*this < rhs) && !(rhs < *this); }
	inline bool operator!=(const type& rhs) const { return (*this < rhs) || (rhs < *this); }
};
template<class W>
struct Edges : private vector<vector<Edge<W>>> {
	using type = vector<vector<Edge<W>>>;
	template<class... Args> Edges(Args... args) : type(args...) {}
	template<class... Args> void add_edge(int u, int v, Args... args) {
		(*this)[u].emplace_back(v, args...);
	}
	using type::begin; using type::end; using type::rbegin; using type::rend;
	using type::cbegin; using type::cend; using type::crbegin; using type::crend;
	using type::size; using type::operator[]; using type::at; using type::back; using type::front;
	using type::reserve; using type::resize; using type::assign; using type::shrink_to_fit;
	using type::clear; using type::erase; using type::insert; using type::swap; 
	using type::push_back; using type::pop_back; using type::emplace_back; using type::empty;
};
template<class W>
struct Graph {
	const int sz;
	Edges<W> e;
	Graph(int n) : sz(n), e(sz) {}
	template<class... Args> void add_edge(int u, int v, Args... args) {
		e.add_edge(u, v, args...);
	}
	int size() {
		return sz;
	}
};
template<class W, class T = W>
struct Graph_D : public Graph<W> {
	vector<T> dist;
	Graph_D(int n) : Graph<W>(n), dist(n) {}
};
template<class W, class T>
void Dijkstra(Graph_D<W, T>& g, int start, T INF_COST) {
	auto& dist = g.dist;
	auto& e = g.e;
	for (auto& ww : dist) ww = INF_COST;
	using Q_T = pair<T, int>;
	using heap = FibHeap<Q_T, greater<>>;
	heap q;
	vector<typename heap::np> node(g.size(), nullptr);
	q.push({0, start}); dist[start] = 0;
	while (!q.empty()) {
		auto a = q.top(); q.pop();
		if (dist[a.second] < a.first) continue;
		for (auto& p : e[a.second]) {
			if (p.w == INF_COST) continue;
			W w = dist[a.second] + p.w;
			if (w < dist[p.to]) {
				dist[p.to] = w;
				if (!node[p.to]) node[p.to] = q.push({w, p.to});
				q.decrease_key(node[p.to], {w, p.to});
			}
		}
	}
}
}
using dijkstra_n::Dijkstra;
template<class T, class U = T> using graph = dijkstra_n::Graph_D<T, U>;

int main() {
	int V, E, S;
	scanf("%d%d%d", &V, &E, &S);
	graph<int> D(V);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		D.add_edge(a, b, c);
	}
	Dijkstra(D, S, INT_MAX);
	for (int i = 0; i < V; i++) {
		if (D.dist[i] == INT_MAX) cout << "INF" << endl;
		else cout << D.dist[i] << endl;
	}
}
