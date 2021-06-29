#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
    std::size_t n;
    std::cin >> n;

    std::size_t a[n];
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
        std::cout << a[i];
        if (i == (n -1)) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    for (std::size_t i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;

        for (int k = 0; k < n; ++k) {
            std::cout << a[k];
            if (k == (n - 1)) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }

    return 0;
}
