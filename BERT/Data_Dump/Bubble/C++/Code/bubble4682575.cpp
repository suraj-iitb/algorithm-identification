#include <iostream>
#include <vector>

template<class T> void output(std::vector<T> & A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << A[n - 1] << std::endl;
}

void swapval(int& a, int& b) {
    const int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(std::vector<int>& A) {
    const int N = A.size();
    bool flag = true;
    int cnt = 0;
    int i = 0;
    while (flag) {
        flag = false;
        for (int j = N - 1; j > i; --j) {
            if (A[j] < A[j-1]) {
                swapval(A[j], A[j - 1]);
                flag = true;
                ++cnt;
            }
        }
        ++i;
    }
    output(A);
    std::cout << cnt << std::endl;

}


int main() {
    int n; std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) std::cin >> A[i];

    bubbleSort(A);

    return 0;
}
