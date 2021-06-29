#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &A, vector<int> &B, int k) {
    vector<int> C(k + 1, 0);
    for (int i = 1; i < A.size(); i++) {
        C.at(A.at(i))++;
    }

    for (int i = 1; i < k + 1; i++) {
        C.at(i) += C.at(i - 1);
    }

    for (int i = B.size() - 1; i > 0; i--) {
        B.at(C.at(A.at(i))) = A.at(i);
        C.at(A.at(i))--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    vector<int> B(n + 1);
    A.at(0) = -1;
    B.at(0) = -1;
    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &A.at(i));
    }

    countingSort(A, B, 10000);

    for (int i = 1; i < n; i++) {
        printf("%d ", B.at(i));
    }
    printf("%d\n", B.at(n));
}
