#include <iostream>
#include <string>


int main() {
    int n, minj, count=0;
    std::cin >> n;

    int A[100];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            std::swap(A[i], A[minj]);
            count++;
        }
    }
    for (int k = 0; k < (n-1); k++) std::cout << A[k] << " ";
    std::cout << A[n-1] << std::endl << count << std::endl;


    return 0;
}



