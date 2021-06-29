#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    int a[n] = {};
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int operation = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if (a[j] < a[j-1]) {
                std::swap(a[j], a[j-1]);
                operation++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
        if (i == (n-1)) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    std::cout << operation << std::endl;

    return 0;
}
