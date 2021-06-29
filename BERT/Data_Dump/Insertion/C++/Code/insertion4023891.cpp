#include<iostream>

using namespace std;

void insertionSort(int A[], int n);
void trace(int A[], int n);

int main()
{
    int n;
    int A[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    insertionSort(A, n);

    return 0;
}

void insertionSort(int A[], int n)
{
    int v;
    int j;

    for (int i = 0; i < n; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = v;

        trace(A, n);
    }
}

void trace(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << ' ';
    }

    cout << A[n - 1] << endl;
}
