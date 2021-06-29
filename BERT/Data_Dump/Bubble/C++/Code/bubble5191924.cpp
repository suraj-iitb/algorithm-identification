#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a.at(i);

    int flag = 1;
    int swap_count = 0;
    while(flag) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (a.at(i) < a.at(i - 1)) {
                int temp = a.at(i);
                a.at(i) = a.at(i - 1);
                a.at(i - 1) = temp;
                swap_count++;
                flag = 1;
            }
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
