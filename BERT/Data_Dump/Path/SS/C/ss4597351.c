#include <iostream>
#include <functional>
#include <memory>
#include <cassert>

template<class T, class E, class Compare = std::less<T>>
struct skew_heap {
	using F = std::function<T(T, E)>;
	using G = std::function<E(E, E)>;
	using value_type = T;
	using operator_type = E;
	using size_type = std::size_t;
private : 
	const Compare c;
	const F f;
	const G g;
	const operator_type ie;
	size_type sz;

	struct node {
	public : 
		value_type val;
		operator_type add;
		std::unique_ptr<node> left, right;
		node (const value_type &x, const operator_type &e) :
			val(x), add(e), left(nullptr), right(nullptr) { }
	};

	using node_ptr = std::unique_ptr<node>;

	node_ptr root;

	node_ptr propagate (node_ptr x) {
		if (not x) return (std::move(x));
		if ((x->add) == ie) return (std::move(x));
		if (x->left) {
			(x->left->add) = g(x->left->add, x->add);
		}
		if (x->right) {
			(x->right->add) = g(x->right->add, x->add);
		}
		(x->val) = f(x->val, x->add);
		(x->add) = ie;
		return (std::move(x));
	}

	node_ptr meld (node_ptr a, node_ptr b) {
		a = propagate(std::move(a));
		b = propagate(std::move(b));
		if (not a) return (std::move(b));
		if (not b) return (std::move(a));
		if (c((a->val), (b->val))) a.swap(b);
		(a->right) = meld(std::move(a->right), std::move(b));
		(a->right).swap(a->left);
		return (std::move(a));
	}

public : 

	skew_heap (const F &f, const G &g, const operator_type &ie) : 
		f(f), g(g), c(), ie(ie), sz(0), root(nullptr) { }

	skew_heap (skew_heap&& rhs) noexcept :
		f(rhs.f), g(rhs.g), c(rhs.c), ie(rhs.ie), sz(rhs.sz), root(std::move(rhs.root)) { }

	constexpr int size () const noexcept {
		return (sz);
	}

	constexpr bool empty () const noexcept {
		return (sz == 0);
	}

	value_type top () {
		assert (not empty());
		return (root->add == ie ? root->val : f(root->val, root->add));
	}

	void pop () {
		assert(not empty());
		root = propagate(std::move(root)); sz--;
		root = meld(std::move(root->left), std::move(root->right));
	}

	void push (const value_type &x) {
		root = propagate(std::move(root)); sz++;
		root = meld(std::move(root), std::make_unique<node>(node(x, ie)));
	}

	void add (const operator_type &x) {
		if (root) (root->add) = g(root->add, x);
	}

	void meld (skew_heap &rhs) {
		(this->sz) += (rhs.sz); rhs.sz = 0;
		(this->root) = meld(std::move(this->root), std::move(rhs.root));
		rhs.root = nullptr;
	}

};


#include <bits/stdc++.h>
using namespace std;

using skewheap = skew_heap<pair<int, int>, int, greater<pair<int, int>>>;
const int INF = (1 << 30);

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	// 辺 (u, v) について、頂点 u に対応するヒープに {cost, v} を push 
	vector<skewheap> edges;
	auto f = [](pair<int, int> p, int b) { p.first += b; return p; };
	auto g = [](int a, int b) { return (a + b); };
	for (int i = 0; i < n; i++) edges.push_back(skewheap(f, g, 0));
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push(make_pair(c, b));
	}
	
	vector<int> dist(n, INF);
	dist[r] = 0;
	skewheap sh(f, g, 0);
	sh.meld(edges[r]);
	
	while (not sh.empty()) {
		int cost, v;
		tie(cost, v) = sh.top();
		sh.pop();
		if (dist[v] > cost) {
			dist[v] = cost;
			edges[v].add(dist[v]);
			sh.meld(edges[v]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
		} else {
			cout << dist[i] << '\n';
		}
	}
	
	return 0;
}
