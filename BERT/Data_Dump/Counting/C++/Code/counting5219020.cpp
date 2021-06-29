#include <iostream>
#include <vector>
#include <map>

void bucket_sort(std::vector<int> &vec) {
    std::map<int, int> bucket;
    for (int i = 0; i < vec.size(); i++) bucket[vec.at(i)] += 1;

    std::map<int, int>::iterator itr;
    for (itr = bucket.begin(); itr != --bucket.end();) {
        int prev = itr->second;
        itr++;
        itr->second += prev;
    }

    std::vector<int> temp = vec;
    for (int i = vec.size() - 1; i >= 0; i--) {
        vec.at(bucket[temp.at(i)] - 1) = temp.at(i);
        bucket[temp.at(i)]--;
    }
}

int main () {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a.at(i);
    bucket_sort(a);
    for (int i = 0; i < n; i++) {
        std::cout << a.at(i);
        if (i < n - 1) std::cout << " ";
        else std::cout << std::endl;
    }

    return 0;
}
