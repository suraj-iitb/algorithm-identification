#include <iostream>
#include <utility>
using namespace std;

void Log(int A[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int BubbleSort(int A[], int n)
{
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; --j) {
            if (A[j-1] > A[j]) {
                swap(A[j-1], A[j]);
                flag = true;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    // Input
    int A[100];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        A[i] = a;
    }

    int cnt = BubbleSort(A, n);

    // Output
    Log(A, n);
    cout << cnt << endl;

    return 0;
}
