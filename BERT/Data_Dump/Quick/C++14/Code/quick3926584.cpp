#include <bits/stdc++.h>
using namespace std;

namespace ext {
	template <class T>
	struct vec_type;
	template <class T>
	constexpr bool is_vec_v;
	using namespace std;
	template<class T>
	struct Vector : std::vector<T> {
		using std::vector<T>::vector;
		char dil = ' ';
		Vector<T> accum() {
			Vector<T> res(this->size() + 1);
			for (size_t i = 0; i < this->size(); i++) {
				res[i+1] = (*this)[i] + res[i];
			}
			return res;
		}
		template<class U = T>
		typename enable_if<is_vec_v<U>, Vector<T>>::type accum2D() {
			const size_t H = this->size();
			const size_t W = (*this)[0].size();
			using S = typename vec_type<U>::type;
			Vector<T> res(H + 1, Vector<S>(W + 1));
			for (size_t i = 0; i < H; i++) {
				for (size_t j = 0; j < W; j++) {
					res[i+1][j+1] = (*this)[i][j];
					res[i+1][j+1] += res[i][j+1];
					res[i+1][j+1] += res[i+1][j];
					res[i+1][j+1] -= res[i][j];
				}
			}
			return res;
		}
		Vector<T> zaatsu() {
			map<T, int> m;
			for (auto& e: *this) m[e] = 1;
			int count = 0;
			for (auto& e: m) e.second = count++;
			Vector<T> res = *this;
			for (auto& e: res) e = m[e];
			return res;
		}
		friend istream& operator>>(istream& is, Vector<T>& t) {
			for (auto& e: t) cin >> e;
			return is;
		}
		friend ostream& operator<<(ostream& os, Vector<T>& t) {
			t.print(' ', os);
			return os;
		}
		void print(char del = ' ', ostream& os = cout) {
			for (size_t i = 0; i < this->size(); i++) {
				os << (*this)[i];
				if (i + 1 != this->size()) os << del;
				os.flush();
			}
		}
		void println(char del = ' ', ostream& os = cout) {
			print(del, os);
			cout << endl;
		}
		long long crossing_merge() {
			auto t = *this;
			return t.crossing_merge_sub();
		}
		// [min_v, max_v)
		long long crossing_bit(T min_v = -1, T max_v = -1) {
			if (min_v == -1) min_v = this->min();
			if (max_v == -1) max_v = this->max() + 1;
			Vector<T> bit(max_v - min_v + 1, 0);
			long long res = 0;
			for (auto e: *this) {
				e = max_v - e;
				for (size_t x = e - 1; x; x -= x & -x) {
					res += bit[x];
				}
				for (size_t x = e; x < bit.size() ; x += x & -x) {
					bit[x]++;
				}
			}
			return res;
		}
		bool permutation() {
			return next_permutation(this->begin(), this->end());
		}
		T& max() {
			return *max_element(this->begin(), this->end());
		}
		T& min() {
			return *min_element(this->begin(), this->end());
		}
private:
		long long crossing_merge_sub() {
			if (this->size() == 1) return 0;
			int x = this->size() / 2;
			Vector<T> left(this->begin(), this->begin() + x);
			Vector<T> right(this->begin() + x, this->end());
			long long res = left.crossing_merge_sub() + right.crossing_merge_sub();
			left.push_back(numeric_limits<T>::max()); right.push_back(numeric_limits<T>::max());
			size_t l = 0, r = 0;
			while (l + r < this->size()) {
				if (left[l] < right[r]) {
					(*this)[l+r] = left[l];
					l++;
				} else {
					(*this)[l+r] = right[r];
					r++;
					res += x - l;
				}
			}
			return res;
		}
	};
	template <class T>
	struct vec_type : std::false_type {};
	template <class T>
	struct vec_type<Vector<T>> : std::true_type {
		using type = T;
	};
	template <class T>
	constexpr bool is_vec_v = vec_type<T>::value;
}
using namespace ext;

int partition(vector<pair<char, int>>& v, int p, int r) {
	int x = v[r].second;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (v[j].second <= x) {
			swap(v[++i], v[j]);
		}
	}
	swap(v[i+1], v[r]);
	return i+1;
}

void quicksort(vector<pair<char, int>>& v, int p, int r) {
	if (p < r) {
		int q = partition(v, p, r);
		quicksort(v, p, q-1);
		quicksort(v, q+1, r);
	}
}

int main() {
	int n; cin >> n;
	vector<pair<char, int>> v;
	for (int i = 0; i < n; i++) {
		char c;
		int x;
		cin >> c >> x;
		v.emplace_back(c, x);
	}
	vector<pair<char, int>> vv(v);
	quicksort(v, 0, n-1);
	stable_sort(vv.begin(), vv.end(), [](auto& l, auto& r) {
		return l.second < r.second;
	});
	if (v == vv) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	for (auto& x : v) {
		cout << x.first << " " << x.second << endl;
	}
}
