#include <iostream>

void print(int n, int a[]) {
    std::cout << a[0];
    for (int i = 1; i < n; i += 1) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    int A[100];
    for (int i = 0; i < N; i += 1) {
        std::cin >> A[i];
    }

    print(N, A);

    for (int i = 1; i < N; i += 1) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j -= 1;
        }
        A[j + 1] = v;

        print(N, A);
    }

    return 0;
}

