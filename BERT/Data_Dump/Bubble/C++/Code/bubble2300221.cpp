#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i != N - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

int bubbleSort(int A[], int N)
{
    int sw = 0;
    bool flag = 1;

    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int A[100], N, i, sw;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    sw = bubbleSort(A, N);

    printArray(A, N);
    cout << sw << endl;
    return 0;
}
