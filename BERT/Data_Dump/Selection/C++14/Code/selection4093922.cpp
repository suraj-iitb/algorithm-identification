#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))

void print_arr(vector<int> &A)
{
    rep (i, 0, A.size())
        if (i != A.size()-1)
            printf("%d ", A[i]);
        else
            printf("%d\n", A[i]);
}

int selection_sort(vector<int> &A)
{
    int cnt = 0;
    rep (i, 0, A.size()) {
        int min_j = i;
        rep (j, i, A.size()) {
            if (A[j] < A[min_j]) {
                min_j = j;
            }
        }
        if (A[i] > A[min_j]) ++cnt;
        swap(A[i], A[min_j]);
    }
    return cnt;
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    rep (i, 0, N) cin >> A[i];

    int cnt = selection_sort(A);
    print_arr(A);
    cout << cnt << endl;
}
