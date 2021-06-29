#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include "bits/stdc++.h"

namespace adaptor = boost::adaptors;

void solve() {
    const int64_t vmax = 10000;

    int64_t n;
    std::cin >> n;

    std::vector<int64_t> A(n + 1), B(n + 1);

    int64_t C[vmax + 1];
    for (int64_t i = 0; i < vmax + 1; i++) {
        C[i] = 0;
    }
    for (int64_t i = 0; i < n; i++) {
        std::cin >> A[i + 1];
        C[A[i + 1]]++;
    }

    for (int64_t i = 1; i < vmax + 1; i++) {
        C[i] += C[i - 1];
    }

    for (int64_t i = n; i > 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for (int64_t i = 1; i < n + 1; i++) {
        if (i > 1) std::cout << " ";
        std::cout << B[i];
    }
    std::cout << std::endl;

    return;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}

