#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int> & A)
{
    cout << A[0];
    for (int i = 1; i < A.size(); ++i) {
        cout << ' ' << A[i];
    }
    cout << endl;
}

void InsertionSort(vector<int> & A)
{
    int n = A.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= i+1; --j) {
            if (A[j-1] > A[j]) {
                swap(A[j], A[j-1]);
                count ++;
            }
        }
    }
    Print(A);
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    // Print(A);
    InsertionSort(A);
    return 0;
}
