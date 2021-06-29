#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> C(10000);

void CountingSort(vector<int>& A, vector<int>& B)
{
    int k = 0;
    for (auto a : A) {
        ++C[a];
        k = max(k, a);
    }
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    for (int i = A.size() - 1; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    vector<int> B(A.size());
    CountingSort(A, B);
    for (int i = 0; i < B.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << B[i];
    }
    cout << endl;
    return 0;
}
