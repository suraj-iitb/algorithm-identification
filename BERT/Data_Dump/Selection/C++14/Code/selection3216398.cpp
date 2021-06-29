#include <iostream>
#include <utility>
static int ssort(int *a, int n) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min > i) {
            std::swap(a[i], a[min]);
            ++c;
        }
    }
    return c;
}
int main() {
    int n, a[100], c;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    c = ssort(a, n);
    for (int i = 0; i < n; ++i) {
        std::cout << ((i == 0) ? "" : " ") << a[i];
    }
    std::cout << std::endl << c << std::endl;
}

