// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

// 簡潔ビットベクトル (数列の長さを N とする)
// n_big <- log^2(N)   (N = 2^32 としたとき、n_big = 32^2 = 1024 = 2^10)
// n_sml <- log(N) / 2 (N = 2^32 としたとき、n_sml = 32/2 = 16 = 2^4)
// n_blk <- n_big を n_sml で割ったもの
// ln_big, ln_sml には、それぞれ log(n_big), log(n_sml) をいれる

template <uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct CompactBitVector {
private:
    using value_type = uint64_t;
    size_t n, n_big, n_sml, n_blk, ln_blk;
    vector<value_type> big, sml, bit;
    
    int popcount(value_type b) const {
        return __builtin_popcountll(b); // GCC builtin function
    }
    void build(vector<int> vec);

public:
    // 構築: O(N)
    CompactBitVector();
    CompactBitVector(vector<int> vec);
    CompactBitVector(vector<int> vec, int k);
    // 数列のサイズ: O(1)
    size_t size() const;
    // 全体の 1 の個数: O(1)
    int count() const;
    // k 番目の値: O(1)
    int value(size_t k) const;
    // [0, k] に存在する 1 の個数: O(1)
    int rank(size_t k) const;
    // [l, r) に存在する 1 の個数: O(1)
    int rank(size_t l, size_t r) const;
    // 1 / 0 の個数 が r を超える、インデックス k 未満最小の要素を返す: O(log N)
    int select1(int r, int k) const;
    int select0(int r, int k) const;
    // k 番目の次に存在する 1 / 0 は何か: O(log N)
    int select1_nxt(size_t k) const;
    int select0_nxt(size_t k) const;
    // k 番目の前に存在する 1 / 0 は何か: O(log N)
    int select1_pre(size_t k) const;
    int select0_pre(size_t k) const;
    // ビットベクトルの k 番目にアクセス
    int at(size_t k) const;
    int operator[](size_t k) const;

    // 出力するだけ
    void show() const {
        cerr << "# big ";
        for(size_t i=0; i<big.size(); i++) {
            cerr << big[i] << " ";
        }
        cerr << endl;
        cerr << "# sml ";
        for(size_t i=0; i<sml.size(); i++) {
            cerr << sml[i] << " ";
        }
        cerr << endl;
        cerr << "# bit ";
        for(size_t i=0; i<bit.size(); i++) {
            cerr << bit[i] << " ";
        }
        cerr << endl;
    }
};

template <uint64_t ln_big, uint64_t ln_sml>
void CompactBitVector<ln_big, ln_sml>::build(vector<int> vec) {
    big.resize(((n + n_big - 1) >> ln_big) + 1); // O(N / log^2 N) memory
    sml.resize(big.size() << ln_blk); // O(N / log N) memory
    bit.resize(big.size() << ln_blk); // O(N / log N) memory
    for(size_t i=0; i<n; i++) {
        size_t b = i >> ln_big;
        big[b+1] += vec[i];
        size_t s = i >> ln_sml, m = i & (n_sml - 1);
        sml[s] += vec[i];
        bit[s] |= (static_cast<value_type>(vec[i]) << m);
    }

    // accumulate
    for(size_t i=1; i<big.size(); i++) big[i] += big[i-1];
    for(size_t i=0; i<big.size(); i++) {
        for(size_t j=1; j<n_blk; j++) {
            sml[(i << ln_blk) + j] += sml[(i << ln_blk) + j - 1];
        }
    }
}

template <uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<ln_big, ln_sml>::CompactBitVector() {}

template <uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<ln_big, ln_sml>::CompactBitVector(vector<int> vec)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),
      n_blk(n_big >> ln_sml), ln_blk(ln_big - ln_sml) {
    build(vec);
}

template <uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<ln_big, ln_sml>::CompactBitVector(vector<int> vec, int k)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),
      n_blk(n_big >> ln_sml), ln_blk(ln_big - ln_sml) {
    vector<int> n_vec;
    for(auto e : vec) n_vec.emplace_back(e >> k & 1);
    build(n_vec);
}

template <uint64_t ln_big, uint64_t ln_sml>
size_t CompactBitVector<ln_big, ln_sml>::size() const {
    return n;
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::count() const {
    return rank(n-1);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::value(size_t k) const {
    if(k >= n) return 0;
    size_t m = k & (n_sml - 1);
    return bit[k >> ln_sml] >> m & 1;
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::rank(size_t k) const {
    if(k >= n) return 0; // for range query
    size_t m = k & (n_sml - 1), mask = (1ULL << n_sml) - (1ULL << (m+1));
    return big[k >> ln_big] + sml[k >> ln_sml] - popcount(bit[k >> ln_sml] & mask);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::rank(size_t l, size_t r) const {
    if(l >= r) return 0;
    return rank(r-1) - rank(l-1);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select1(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select0(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(mid + 1 - rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select1_nxt(size_t k) const {
    return select1(rank(k), n);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select0_nxt(size_t k) const {
    return select0(rank(k), n);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select1_pre(size_t k) const {
    return select1(rank(k) - 1 - value(k), k);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::select0_pre(size_t k) const {
    return select0(rank(k) - 1 - value(k), k);
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::at(size_t k) const {
    return bit[k >> ln_sml] >> (k & (n_sml - 1)) & 1;
}

template <uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<ln_big, ln_sml>::operator[](size_t k) const {
    return at(k);
}

// ウェーブレット行列 (Wavelet Matrix)
// w は word_size (ビット幅), 30 bit で表現できる整数なら 30
template <uint64_t word_size = 30, typename value_type = int,
          uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct WaveletMatrix {
private:
    using BitVector = CompactBitVector<ln_big, ln_sml>;
    array<BitVector, word_size> vecs;

    // 要素数
    int n;
    // k ビット目を基準に安定ソート
    vector<value_type> sort_kth_bit(const vector<value_type>& vec, int k) const;

    // [l, r) の範囲内にある x と等しい要素は最下段のどの範囲に相当？
    // select するときに利用
    pair<int, int> rank_range(int l, int r, value_type x) const;    
public:
    // クエリは特に注釈がない限り 0-indexed
    // 構築: O(N w)
    WaveletMatrix(vector<value_type> vec);

    // k 番目の値を復元: O(w)
    value_type at(int k) const;
    value_type operator[](int k) const;

    // [l, r) の範囲内に以下が何個存在するか: O(w)
    // ・x より小さい要素
    // ・x と等しい要素
    // ・x より大きい要素
    tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;
    tuple<int, int, int> rank_tuple(value_type x) const;
    
    // [l, r) の範囲内で k 番目 (1-indexed) に小さい要素が何か: O(w)
    value_type quantile(int l, int r, int k) const;
    value_type quantile(int k) const;

    // [l, r) の範囲内の m 未満 / m を超える 要素はいくつか: O(w)
    int freq_less(int l, int r, value_type m) const;
    int freq_less(value_type m) const;
    int freq_greater(int l, int r, value_type m) const;
    int freq_greater(value_type m) const;
    
    // [l, r) の範囲内に x \in [mi, ma] を満たす x がいくつ出てきたか: O(w)
    // [mi, ma] は閉区間！！ 
    int freq(int l, int r, value_type mi, value_type ma) const;
    int freq(int l, int r, value_type x) const;
    int freq(value_type mi, value_type ma) const;
    
    // [l, r) の範囲内にある要素の最小値 (quantile 再利用): O(w)
    value_type min_value(int l, int r) const;
    value_type min_value() const;

    // [l, r) の範囲内にある要素の最大値 (quantile 再利用): O(w)
    value_type max_value(int l, int r) const;
    value_type max_value() const;

    // [l, r) の範囲内にある k 番目 (1-indexed) の x の位置: O(w log N)
    int select(int l, int r, int k, value_type x) const;
    int select(int k, value_type x) const;

    // k 番目の要素と値が等しいもので、k 番目の直後 / 直前の要素 idx: O(w log N)
    int next(int k) const;
    int prev(int k) const;
};

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
vector<value_type> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::sort_kth_bit(const vector<value_type>& vec, int k) const {
    vector<value_type> v0, v1;
    v0.reserve(vec.size()), v1.reserve(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);
    }
    /*
    for(auto e : v0) cerr << e << " ";
    cerr << "| ";
    for(auto e : v1) cerr << e << " ";
    cerr << endl;
    */
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
pair<int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_range(int l, int r, value_type x) const {
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return make_pair(l, r);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
WaveletMatrix<word_size, value_type, ln_big, ln_sml>::WaveletMatrix(vector<value_type> vec) : n(vec.size()) {
    /*
    fprintf(stderr, "raw: ");
    for(auto e : vec) cerr << e << " ";
    cerr << endl;
    */    

    vecs[0] = BitVector(vec, word_size - 1);

    /*
    fprintf(stderr, "# ");
    for(size_t i=0; i<vec.size(); i++) {
        cerr << vecs[0][i] << " ";
    }
    cerr << endl;
    */

    for(size_t i=1; i<word_size; i++) {
        // fprintf(stderr, "bit = %zu: ", word_size - i);
        vec = sort_kth_bit(vec, word_size - i);
        vecs[i] = BitVector(vec, word_size - i - 1);

        /*
        fprintf(stderr, "# ");
        for(size_t j=0; j<vec.size(); j++) {
            cerr << vecs[i][j] << " ";
        }
        cerr << endl;
        */
    }
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::at(int k) const {
    int b = k; value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(b), cnt0 = b + 1 - cnt1;
        if(vecs[i][b] == 1) {
            res |= (1ULL << (word_size - 1 - i));
            b = all0 + cnt1 - 1;
        }
        else {
            b = cnt0 - 1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::operator[](int k) const {
    return at(k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(int l, int r, value_type x) const {
    int small = 0, equal = 0, big = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            small += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            big += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    equal = r - l;
    return make_tuple(small, equal, big);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(value_type x) const {
    return rank_tuple(0, n, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, int k) const {
    value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(cnt0 >= k) {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
        else {
            k -= cnt0;
            res |= 1ULL << (word_size - 1 - i);
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int k) const {
    return quantile(0, n, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            res += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(value_type m) const {
    return freq_less(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            res += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(value_type m) const {
    return freq_greater(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type mi, value_type ma) const {
    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type x) const {
    return freq(l, r, x, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(value_type mi, value_type ma) const {
    return freq(0, n, mi, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r) const {
    return quantile(l, r, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value() const {
    return min_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r) const {
    return quantile(l, r, r - l);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value() const {
    return max_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int l, int r, int k, value_type x) const {
    if(k <= 0) return -1;
    tie(l, r) = rank_range(l, r, x);
    if(r - l < k) return -1;

    // fprintf(stderr, "l = %d, r = %d\n", l, r);
    int pos = l + k - 1;
    for(size_t i=0; i<word_size; i++) {
        int b = x >> i & 1;
        // fprintf(stderr, "pos = %d, b = %d\n", pos, b);
        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;
        // fprintf(stderr, "cnt1 = %d, cnt0 = %d\n", cnt1, cnt0);
        if(b == 0) {
            int m = pos;
            // fprintf(stderr, "type 0: m = %d\n", m);
            pos = vecs[word_size - 1 - i].select0(m, n);
        }
        else {
            int m = pos - cnt0;
            // fprintf(stderr, "type 1: m = %d\n", m);
            pos = vecs[word_size - 1 - i].select1(m, n);
        }
    }
    return pos;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int k, value_type x) const {
    return select(0, n, k, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m-1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m+1, at(k));
}

int main() {
    int N; scanf("%d", &N);
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    WaveletMatrix<14> wm(A);
    for(int i=0; i<N; i++) printf("%d%c", wm.quantile(i+1), " \n"[i + 1 == N]);
    return 0;
}

