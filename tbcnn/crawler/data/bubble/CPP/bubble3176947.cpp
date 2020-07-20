#include <iostream>

#define MAX_N 100

int N;
int A[MAX_N];

void bubble_sort() {
    int  counter=0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j=N-1; j>=1; j--) {
            if (A[j] < A[j-1]) {
                std::swap(A[j], A[j-1]);
                counter++;
                flag = true;
            }
        }
    }

    for (int i=0; i<N-1; i++) std::cout << A[i] << ' ';
    std::cout << A[N-1] << std::endl;
    std::cout << counter << std::endl;
}

int main() {
    std::cin >> N;
    for (int i=0; i<N; i++) std::cin >> A[i];
    
    bubble_sort();

    return 0;
}

