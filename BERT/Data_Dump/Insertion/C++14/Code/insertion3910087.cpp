#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

static void dump(std::vector<int> const& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it != vec.begin()) {
            std::cout << ' ';
        }
        std::cout << *it;
    }
    std::cout << '\n';
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    std::copy_n(std::istream_iterator<int>{std::cin}, vec.size(), vec.begin());
    dump(vec);

    for (std::size_t i = 1; i < vec.size(); ++i) {
        auto v = vec[i];

        auto j = i;
        for (; j-- != 0 && vec[j] > v;) {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = v;

        dump(vec);
    }
}

// vim:sw=4:

