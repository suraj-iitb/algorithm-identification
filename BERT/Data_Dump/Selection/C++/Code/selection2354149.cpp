#include <iostream>
#include <vector>

void selection(std::vector<int> a, int n) {
    int minj;
    int change_count = 0;
    int temp; // use to swap two elements in vector
    bool change_check;
    for (int i = 0; i < n - 1; i++) {
        minj = i;    
        change_check = false;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
                change_check = true;
            }
        }
        if (change_check == true) {
            temp = a[minj]; 
            a[minj] = a[i]; 
            a[i] = temp;
            change_count++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << a[n - 1] << std::endl;;
    std::cout << change_count << std::endl;;
    return;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    selection(a, n);
    return 0;
}
