
#include <bits/stdc++.h>

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

using namespace std;

typedef long long LL;

auto INF = make_pair('J', 1 << 30);

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "[ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "]";

    return os;
}

void print(pair<char, int>* A, int n) {
    REP(i, n) {
        cout << A[i].first << " " << A[i].second << endl;
    }
}

int partition(pair<char, int>* A, int p, int r) {
    int pivot = A[r].second;
    int i = p - 1;

    FOR(j, p, r) {
        if(A[j].second <= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[++i], A[r]);

    return i;
}

void quickSort(pair<char, int>* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q + 1, r);
    }
}

void check_stable(pair<char, int>* sorted, pair<char, int>* original, int left, int right) {

    int index = 0, current_n = 0;
    FOR(i, left, right) {
        auto cur = sorted[i];

        if (cur.second != current_n) {
            current_n = cur.second;
            index = 0;
        }

        FOR(j, left, right) {
            if (cur == original[j]) {
                if (index > j) {
                    cout << "Not stable" << endl;
                    return;
                }

                index = j;
            }
        }
    }

    cout << "Stable" << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    pair<char, int> D[n];
    REP(i, n) {
        char mark; int num;
        cin >> mark >> num;
        D[i] = make_pair(mark, num);
    }

    // copy deck to check stability
    pair<char, int> D_copy[n] = D;

    quickSort(D, 0, n-1);

    check_stable(D, D_copy, 0, n - 1);

    print(D, n);

}

