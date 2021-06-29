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

    int mini;
    int op = 0;
    for (int i = 0; i < n; ++i) {
        mini = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            std::swap(a[i], a[mini]);
            op++;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
        if (i == (n -1)) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    std::cout << op << std::endl;

    return 0;
}
