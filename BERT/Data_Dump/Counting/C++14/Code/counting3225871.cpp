#include <iostream>
int n, k, a[2000001], b[2000001], c[2000001];
static void csort(void) {
    for (int i = 0; i <= k; ++i) {
        c[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        ++c[a[i]];
    }
    for (int i = 1; i <= k; ++i) {
        c[i] += c[i - 1];
    }
    for (int i = n; i > 0; --i) {
        b[c[a[i]]] = a[i];
        --c[a[i]];
    }
}
int main() {
    std::cin >> n;
    k = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (k < a[i]) {
            k = a[i];
        }
    }
    csort();
    for (int i = 1; i <= n; ++i) {
        std::cout << ((i == 1) ? "" : " ") << b[i];
    }
    std::cout << std::endl;
}

