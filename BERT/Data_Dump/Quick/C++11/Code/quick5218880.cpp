#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using Card = std::pair<char, int>;

int partition(std::vector<Card> &vec, int p, int r) {
    int x = vec.at(--r).second;
    int i = p;
    for (int j = p; j < r; j++) {
        if (vec.at(j).second <= x) {
            std::swap(vec.at(j), vec.at(i++));
        }
    }
    std::swap(vec.at(i), vec.at(r));
    return i;
}

void quick_sort(std::vector<Card> &vec, int p, int r) {
    if (p < r) {
        int base = partition(vec, p, r);
        quick_sort(vec, p, base);
        quick_sort(vec, base + 1, r);
    }
}

void merge_vec(std::vector<Card> &vec, int left, int mid, int right) {
    std::vector<Card> vec_left;
    std::vector<Card> vec_right;
    for (int i = left; i < mid; i++) vec_left.push_back(vec.at(i));
    for (int i = mid; i < right; i++) vec_right.push_back(vec.at(i));
    vec_left.push_back(std::make_pair('J', 1e9 + 1));
    vec_right.push_back(std::make_pair('J', 1e9 + 1));

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (vec_left.at(i).second <= vec_right.at(j).second) {
            vec.at(k) = vec_left.at(i++);
        }
        else {
            vec.at(k) = vec_right.at(j++);
        }
    }
}

void merge_sort(std::vector<Card> &vec, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(vec, left, mid);
        merge_sort(vec, mid, right);
        merge_vec(vec, left, mid, right);
    }
}

bool is_stable(std::vector<Card> vec1, std::vector<Card> vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1.at(i).first != vec2.at(i).first) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Card> vec_quick(n);
    std::vector<Card> vec_merge(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec_quick.at(i).first >> vec_quick.at(i).second;
    }
    vec_merge = vec_quick;

    merge_sort(vec_merge, 0, n);
    quick_sort(vec_quick, 0, n);

    if (is_stable(vec_merge, vec_quick)) std::cout << "Stable" << std::endl;
    else std::cout << "Not stable" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << vec_quick.at(i).first << " " << vec_quick.at(i).second << std::endl;
    }

    return 0;
}
