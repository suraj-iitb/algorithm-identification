#include <cstdio>

using namespace std;

#define REP(i, I, N) for (int i = I; i < N; ++i)
#define rep(i, N) REP(i, 0, N)
#define MAX 5000000
#define INFTY 20000000000

typedef long long int ll;
ll L[MAX / 2 + 2], R[MAX / 2 + 2];
int counter = 0;

void merge(ll A[], ll left, ll mid, ll right) {
    ll n1 = mid - left;
    ll n2 = right - mid;
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = R[n2] = INFTY;
    ll i = 0, j = 0;
    REP(k, left, right) {
        counter++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(ll A[], ll left, ll right) {
    if (left + 1 < right) {
        ll mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    ll n;
    scanf("%d", &n);
    ll S[MAX];
    rep(i, n) scanf("%d", &S[i]);
    mergeSort(S, 0, n);

    for (ll i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%lld", S[i]);
    }
    printf("\n");
    printf("%d\n", counter);
    return 0;
}

