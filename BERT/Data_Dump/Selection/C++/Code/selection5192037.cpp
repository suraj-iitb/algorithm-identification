#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a.at(i);

    int swap_count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (a.at(j) < a.at(minj)) minj = j;
        }
        if (minj != i) {
            int temp = a.at(i);
            a.at(i) = a.at(minj);
            a.at(minj) = temp;
            swap_count++;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a.at(i);
        if (i < n - 1) std::cout << " ";
        else  std::cout << std::endl;
    }
    std::cout << swap_count << std::endl;

    return 0;
}
