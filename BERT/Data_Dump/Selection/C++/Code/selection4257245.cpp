#include <bits/stdc++.h>

void printAll(std::vector<int> A) {
    for (int i = 0; i < (A.size()-1); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A.back() << std::endl;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int count = 0;
    int mini, tmp;
    for (int i = 0; i < A.size(); i++) {
        mini = i;
        for (int j = i; j < A.size(); j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }

        if (mini != i) {
            tmp = A[mini];
            A[mini] = A[i];
            A[i] = tmp;
            count++;
        }
    }

    printAll(A);
    std::cout << count << std::endl;
    
}
