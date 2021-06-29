#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

static const int kOrg = 1;

int countingSort(std::vector<int>& A, std::vector<int>& B, int k, int n)
{
    std::vector<int> C(k+1);

    // A[]の数の個数を保持
    for (int j = kOrg; j < n + kOrg; j++) {
        C[A[j]]++;
    }

    // C[]にA[]以下の総和を求める
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // ソート後に戻す
    for (int j = n - 1 + kOrg; j >= kOrg; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    return 0;
}


int main(void)
{
    // 計数ソート
    int n = 0;
    std::cin >> n;

    std::vector<int> A(n + kOrg);
    std::vector<int> B(n + kOrg);

    for (int i = kOrg; i < n + kOrg; i++) {
        std::cin >> A[i];
    }

    // 配列の最大数を決めるため最大値を取る
    int k = *std::max_element(A.begin(), A.end());

    countingSort(A, B, k, n);

    if (n > 0) {
        printf("%d", B[kOrg]);
        for (int i = kOrg + 1; i < n + kOrg; i++) {
            printf(" %d", B[i]);
        }
        printf("\n");
    }
    return 0;
}

