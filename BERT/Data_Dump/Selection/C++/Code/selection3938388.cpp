#include <iostream>
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

int SelectionSort(int A[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        int minA = A[i];
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < minA) {
                minA = A[j];
                idx = j;                
            }
        }
        if (i != idx) {
            swap(A[i], A[idx]);
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    int A[100];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        A[i] = a;
    }

    int cnt = SelectionSort(A, n);
    Log(A, n);
    cout << cnt << endl;

    return 0;
}
