#include <iostream>
#include <vector>

int count_ans = 0;

int merge_vec(std::vector<int> &vec, int left, int mid, int right) {
    std::vector<int> vec_left;
    std::vector<int> vec_right;
    for (int i = left; i < mid; i++) vec_left.push_back(vec.at(i));
    for (int i = mid; i < right; i++) vec_right.push_back(vec.at(i));
    vec_left.push_back(1e9 + 1);
    vec_right.push_back(1e9 + 1);

    int count = 0;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        count++;
        if (vec_left.at(i) < vec_right.at(j)) {
            vec.at(k) = vec_left.at(i++);
        }
        else {
            vec.at(k) = vec_right.at(j++);
        }
    }
    return count;
}

void merge_sort(std::vector<int> &vec, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(vec, left, mid);
        merge_sort(vec, mid, right);
        count_ans += merge_vec(vec, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a.at(i);
    merge_sort(a, 0, n);
    for (int i = 0; i < n; i++) {
        std::cout << a.at(i);
        if (i < n - 1) std::cout << " ";
        else std::cout << std::endl;
    }
    std::cout << count_ans << std::endl;

    return 0;
}
