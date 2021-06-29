#include <iostream>
#include <array>
void print_line(int* A, int N) {
    for(auto i=0; i<N; i++) {
        std::cout << A[i] << ((i<(N-1) ? " " : ""));
    }
    std::cout << std::endl;
}

void insertionSort(int* A, int N) {
    print_line(A,N);
    for(auto i=1; i<N; i++) {
        int v{A[i]};
        int j{i-1};
        while(j>=0 && A[j]>v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print_line(A,N);
    }
}

int main() {
    int N{};
    std::cin >> N;
    int A[N];
    for(auto i=0; i<N; i++) {
        std::cin >> A[i];
    }
    insertionSort(A,N);
}

