#include <cstdio>

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
    print_num();
    for(int i = 1;i < n;++ i) {
        int j = i - 1;
        int key = num[i];
        while(j >= 0 && num[j] > key) {
            num[j + 1] = num[j];
            -- j;
        }
        num[j + 1] = key;
        print_num();
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;++ i) scanf("%d", &num[i]);
    solve();
}
