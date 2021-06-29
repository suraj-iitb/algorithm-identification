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
        int min_j = i;
        for (int j = i+1; j < n; ++j) {
            if (A[min_j] > A[j]) {
                min_j = j;
            }
        }
        if (i != min_j) {
            swap(A[i], A[min_j]);
            count ++;
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
