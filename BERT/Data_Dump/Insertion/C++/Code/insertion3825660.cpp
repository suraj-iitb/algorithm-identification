#include <iostream>
#include <string>

int main() {
    int n, m[100], j, key;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    for (int i = 0; i < n; i++) {
        
        key = m[i];
        j = i - 1;
        while (j >= 0 && m[j] > key) {
            m[j+1] = m[j];
            j--;
        }
        m[j+1] = key;

        for (int k = 0; k < n; k++) {
            if (k == n - 1) {
                std::cout << m[k];
            } else {
                std::cout << m[k] << " ";
            }
            
        }
        std::cout << std::endl;
    }

   
}
