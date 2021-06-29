#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include "bits/stdc++.h"

namespace adaptor = boost::adaptors;

const int64_t max = 500000;
const int64_t sentinel = 10000000000;

int64_t L[max / 2 + 2], R[max / 2 + 2];
int64_t cnt;

void merge(int64_t A[], int64_t n, int64_t left, int64_t mid, int64_t right) {
    int64_t n1 = mid - left;
    int64_t n2 = right - mid;
    for (int64_t i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int64_t i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = sentinel;
    int64_t i = 0, j = 0;
    for (int64_t k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int64_t A[], int64_t n, int64_t left, int64_t right) {
    if (left + 1 < right) {
        int64_t mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

void solve() {
    int64_t A[max], n;
    std::cin >> n;
    for (int64_t i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    mergeSort(A, n, 0, n);

    for (int64_t i = 0; i < n; i++) {
        if (i > 0) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
    return;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}

