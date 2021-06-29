#include <iostream>

int bubbleSort(int a[], int n) {
    int x = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j >= 1; j--) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 1;
                x++;
            }
        }
    }
    return x;
}

int main(int argc, const char *argv[]) {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int x = bubbleSort(a, n);
    
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
    
    std::cout << x << std::endl;
    
    return 0;
}
