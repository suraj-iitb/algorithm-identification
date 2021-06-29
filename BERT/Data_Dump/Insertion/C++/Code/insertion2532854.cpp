#include <iostream>
#include <vector>
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
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        Print(A);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    Print(A);
    InsertionSort(A);
    return 0;
}
