#include <iostream>

int main() {
    int n, v, k;
    int a[100];
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }

    for (int j = 1; j < n ; j++) {
            for (int m = 0; m < n; m++) {
                if (m == n - 1) {
                    std::cout << a[m];    
                } else {
                    std::cout << a[m] << " ";
                }
            }
            std::cout << std::endl;
        v = a[j];
        k = j - 1;
        while (k >= 0 && a[k] > v){
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = v;
    }
    
    
    for (int m = 0; m < n; m++) {
            if (m == n - 1) {
                std::cout << a[m];    
            } else {
                std::cout << a[m] << " ";
            }
        }
    std::cout << std::endl;
    
    
}
