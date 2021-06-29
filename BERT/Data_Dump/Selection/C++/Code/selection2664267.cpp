#include <iostream>
#include <vector>
 
int selectionSort(std::vector<int>& a, int n) {
    int x = 0;
    int minj = 0;
    for (int i = 0; i < n - 1; i++) {
        minj = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            std::iter_swap(a.begin() + i, a.begin() + minj);
            x++;
        }
    }
    return x;
}
 
int main(int argc, const char *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
     
    int x = selectionSort(a, n);
     
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
     
    std::cout << x << std::endl;
     
    return 0;
}
