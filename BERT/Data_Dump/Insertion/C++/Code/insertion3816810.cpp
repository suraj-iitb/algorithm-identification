#include <iostream>
#include <vector>

int main() {
        int N;
        std::cin >> N;
        std::vector<int> A;

        for (int i = 0; i < N; i++) {
                int x;
                std::cin >> x;
                A.push_back(x);
        }

        std::cout << A[0];
        for (int i = 1; i < N; i++) {
                std::cout << " " << A[i];
        }
        std::cout << std::endl;

        for (int i = 1; i <= N - 1; i++) {
                int v = A[i];
                int j = i - 1;

                while (j >= 0 && A[j] > v) {
                        A[j+1] = A[j];
                        j--;
                }
                A[j+1] = v;

                std::cout << A[0];
                for (int i = 1; i < N; i++) {
                        std::cout << " " << A[i];
                }
                std::cout << std::endl;
        }
}

