#include <iostream>

void print_array(int *a, int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0) std::cout << " ";
        std::cout << a[i];
    }
    std::cout << "\n";
}

void sort(int *a, int size) {
    int j, v;
    for (int i = 1; i < size; i++) {
        print_array(a, size);
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
            a[j + 1] = v;
        }
    }
}

int main() {
    const int MAX = 100;
    int N;
    int a[MAX];
    std::cin >> N;
    for (int i = 0; i < N; i++) std::cin >> a[i];
    sort(a, N);
    print_array(a, N);
    return 0;
}
