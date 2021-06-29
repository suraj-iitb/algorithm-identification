#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

void CountingSort(vector<int> A, vector<int> &B, int k)
{
    vector<int> C;
    repi(i, k + 1, 0)
    {
        C.push_back(0);
    }
    repi(i, A.size(), 0)
    {
        C.at(A.at(i))++;
    }
    repi(i, k + 1, 1)
    {
        C.at(i) += C.at(i - 1);
    }
    for (int i = A.size() - 1; i >= 0; i--)
    {
        B.at(C.at(A.at(i))-1) = A.at(i);
        C.at(A.at(i))--;
    }
}

int main()
{
    int n, k = 0;
    cin >> n;
    vector<int> A(n, 0), B(n, 0);
    repi(i, n, 0)
    {
        cin >> A[i];
        k = max(A.at(i), k);
    }
    CountingSort(A, B, k);
    repi(i, n, 0)
    {
        cout << B.at(i) << ((i + 1) % n ? " " : "\n");
    }

    return 0;
}
