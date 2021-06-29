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

int main() {
    int A[1000], N, v, i, j;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
    printArray(A, N);
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printArray(A, N);
    }
    
    return 0;
}
