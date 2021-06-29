#include <iostream>

int bubbleSort(int* a, int n) {
    int swap_count{};
    bool flag{true};
    while(flag) {
        flag = false;
        for(auto i=n-1; i>0; i--) {
            if(a[i]<a[i-1]) {
                std::swap(a[i],a[i-1]);
                swap_count++;
                flag = true;
            }
        }
    }
    return swap_count;
}

int main() {
    int n{}; std::cin >> n;
    int a[n]{}; for(auto i=0; i<n; i++) std::cin >> a[i];
    int swap_count = bubbleSort(a, n);
    for(auto i=0; i<n; i++) std::cout << a[i] << ((i<n-1) ? " " : "");
    std::cout << std::endl << swap_count << std::endl;
}

