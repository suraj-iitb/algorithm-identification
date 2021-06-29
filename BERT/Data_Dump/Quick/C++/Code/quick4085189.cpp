#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include "bits/stdc++.h"

namespace adaptor = boost::adaptors;

const int64_t max = 100000;
const int64_t sentinel = 10000000000;

struct Card {
    char suit;
    int64_t value;
};

Card L[max / 2 + 2], R[max / 2 + 2];

void merge(Card A[], int64_t n, int64_t left, int64_t mid, int64_t right) {
    int64_t n1 = mid - left;
    int64_t n2 = right - mid;
    for (int64_t i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int64_t i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1].value = R[n2].value = sentinel;

    int64_t i = 0, j = 0;
    for (int64_t k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int64_t n, int64_t left, int64_t right) {
    int64_t mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int64_t partition(Card A[], int64_t n, int64_t p, int64_t r) {
    int64_t i, j;
    Card x;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(Card A[], int64_t n, int64_t p, int64_t r) {
    if (p < r) {
        int64_t q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q, r);
    }
}

void solve() {
    int64_t n;
    std::cin >> n;

    Card A[max], B[max];
    char s;
    int64_t v;
    for (int64_t i = 0; i < n; i++) {
        std::cin >> s >> v;
        A[i].suit = B[i].suit = s;
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    bool stable = true;
    for (int64_t i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) stable = false;
    }

    if (stable) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }

    for (int64_t i = 0; i < n; i++) {
        std::cout << B[i].suit << " " << B[i].value << std::endl;
    }

    return;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}

