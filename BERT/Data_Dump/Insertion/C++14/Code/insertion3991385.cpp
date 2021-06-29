#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmix(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ld = long double;

#define ALL(x) (x).begin(), (x).end()
template<class T>
using vc = vector<T>;
using vi = vc<int>;
using vvi = vc<vi>;

template<class T>
using va = valarray<T>;
using vad = va<ld>;

vi Read(ll n) {
    auto      v = vi(n);
    for (auto i = std::size_t(0); i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

template <class T>
void Dump(const T& A){
    REP(i, A.size() - 1) cout << A[i] << " ";
    cout << A[A.size() - 1] << "\n";
}

void insertionSort(vi& A, int N){
    FOR(i, 1, N){
        Dump(A);
        const auto v = A[i];
        auto j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = v;
    }
}

int main() {
    int N;
    cin >> N;
    auto A = Read(N);

    insertionSort(A, N);
    Dump(A);
}

