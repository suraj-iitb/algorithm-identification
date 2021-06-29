#include <cstdio>
#include <vector>
#define MAX 10001
#define LEN 2000000
typedef long long ll;

using namespace std;

int c[MAX] = {0};
int a[LEN], b[LEN];

int main() {


    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
    for (int i = 1; i < MAX; i++) {
        c[i] += c[i-1];
    }

    for (long long  i = n-1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");
}


