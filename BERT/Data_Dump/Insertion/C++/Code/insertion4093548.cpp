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

void insertion_sort(int N, vector<int> A)
{
    for (int i = 0; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 and A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print_arr(A);
    }
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    rep (i, 0, N) cin >> A[i];

    insertion_sort(N, A);
}
