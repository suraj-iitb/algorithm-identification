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

void print_arr(vector<int> A)
{
    rep (i, 0, A.size())
        if (i != A.size()-1)
            printf("%d ", A[i]);
        else
            printf("%d\n", A[i]);
}

int bubble_sort(int N, vector<int> &A)
{
    int cnt = 0;
    bool flg = true;
    while (flg) {
        flg = false;
        for (int i = A.size()-1; i >= 0; i--) {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
//                int tmp = A[i];
//                A[i] = A[i-1];
//                A[i-1] = tmp;
                ++cnt;
                flg = true;
            }
        }
    }
    return cnt;
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    rep (i, 0, N) cin >> A[i];

    int cnt = bubble_sort(N, A);
    print_arr(A);
    cout << cnt << endl;
}
