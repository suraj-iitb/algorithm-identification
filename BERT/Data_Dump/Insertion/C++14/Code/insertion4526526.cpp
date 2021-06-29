#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> v) {
    for (size_t i = 0, len = v.size(); i < len; i++) {
        std::cout << v[i];
        if (i != len - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::string buf;

    std::cin >> n;
    std::vector<int> v;
    v.reserve(n);

    while (std::cin >> buf) {
        v.push_back(std::stoi(buf));
    }

    print_vector(v);
    for (size_t i = 1; i < n; i++) {
        int a = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > a) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = a;
        print_vector(v);
    }
}

