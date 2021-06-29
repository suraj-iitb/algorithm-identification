#include <iostream>

int main() {
    int A[10000] = {};
    int n = 0;
    std::cin >> n;
    int input_value;
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> input_value;
        A[input_value]++;
        if (input_value > max_value) {
            max_value = input_value;
        }
    }

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < A[i]; j++) {
            std::cout << i;
            if (j != A[i] - 1) {
                std::cout << " ";
            } else if (i == max_value) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }
}

