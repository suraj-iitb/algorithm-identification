#include <iostream>

int main()
{
    int n;
    int a[100];
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int k = 0; k < n; ++k) {
        std::cout << a[k];
        if (k != n - 1) std::cout << " ";
        else std::cout << std::endl;
    }
    // Insersion Sort
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
        for (int k = 0; k < n; ++k) {
            std::cout << a[k];
            if (k != n - 1) std::cout << " ";
            else std::cout << std::endl;
        }
    }
}

