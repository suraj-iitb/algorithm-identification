#include <iostream>

void selectoinSort(int* a, int n) {
    int swap_count{};
    for(auto i=0; i<n; i++) {
        int minj{i};
        for(auto j=i; j<n; j++) {
            minj = (a[j]<a[minj]) ? j : minj;
        }
        std::swap(a[i], a[minj]);
        swap_count += (i!=minj) ? 1 : 0;
    }
    for(auto i=0; i<n; i++) {
        std::cout << a[i] << ((i<n-1) ? " " : "\n");
    }
    std::cout << swap_count << std::endl;
}

int main() {
    int n{}; std::cin >> n;
    int a[n]; for(auto i=0; i<n; i++) std::cin >> a[i];
    selectoinSort(a, n);
}

