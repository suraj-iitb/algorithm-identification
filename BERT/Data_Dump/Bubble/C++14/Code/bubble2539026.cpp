#include <bits/stdc++.h>

using namespace std;

namespace {

    typedef double real;
    typedef long long ll;

    template<class T> ostream& operator<<(ostream& os, const vector<T>& vs) {
        if (vs.empty()) return os << "[]";
        auto i = vs.begin();
        os << "[" << *i;
        for (++i; i != vs.end(); ++i) os << " " << *i;
        return os << "]";
    }
    template<class T> istream& operator>>(istream& is, vector<T>& vs) {
        for (auto it = vs.begin(); it != vs.end(); it++) is >> *it;
        return is;
    }

    template<typename INT>
    struct BinaryIndexedTree {
        int n;
        vector<INT> data; // data[i]???[floor2(i), i)???????????????. ?????????floor2???2????????¢??°.
        BinaryIndexedTree(int n) : n(n), data(n + 1, 0) {}
        INT sum(int i) {
            // [0, i)???????????????
            INT s = 0;
            while (i > 0) {
                s += data.at(i);
                i -= (i & -i);
            }
            return s;
        }
        void add(int i, INT x) {
            // ??????i???x?????????
            i++;
            while (i <= n) {
                data.at(i) += x;
                i += (i & -i);
            }
        }
    };

    ll countInversion(const vector<int>& perm) {
        // [0, n)?????????perm?????¢?????°?????°??????. ?¨???????O(N).
        // [0, n)??????????????????????????????????????????????????????. ????????¨???.
        ll n = perm.size();
        ll ans = 0;
        BinaryIndexedTree<ll> bit(n);
        for (int i = 0; i < n; i++) {
            ans += i - bit.sum(perm[i]);
            bit.add(perm[i], 1);
        }
        return ans;
    }

    int N;
    vector<int> P;
    void input() {
        cin >> N;
        P.resize(N);
        cin >> P;
    }

    template<typename T>
    vector<int> rank(vector<T> xs) {
        vector<int> rank(xs.size());
        iota(rank.begin(), rank.end(), 0);
        stable_sort(rank.begin(), rank.end(), [&](int a, int b) -> bool {
            return xs[a] < xs[b];
        });
        return rank;
    }

    void solve() {
        auto ans = countInversion(forward<vector<int>>(rank(P)));
        stable_sort(P.begin(), P.end());
        bool flg = true;
        for (auto p : P) {
            if (flg) {
                flg = false;
            } else {
                cout << " ";
            }
            cout << p;
        }
        cout << endl;
        cout << ans << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}
