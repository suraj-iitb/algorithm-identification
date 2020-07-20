#include <cstdio>
#include <algorithm>

using namespace std;

const int kMax = 100 + 5;

int n;
int num[kMax];

void print_num() {
    for(int i = 0;i < n;++ i) {
        if(i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
}

void solve() {
    int res = 0;
    for(int i = 1;i < n;++ i) {
        for(int j = i - 1;j >= 0;-- j) {
            if(num[j] > num[j + 1]) swap(num[j], num[j + 1]), ++ res;
        }
    }
    print_num();
    printf("%d\n", res);
}

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;++ i) scanf("%d", &num[i]);
    solve();
}
