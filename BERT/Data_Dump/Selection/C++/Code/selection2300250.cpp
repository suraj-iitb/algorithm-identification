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

int selectionSort(int A[], int N){
    int minj;
    int sw = 0;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            sw++;
        }

        swap(A[i], A[minj]);
    }
    return sw;
}

int main() {
    int A[100], N, i, sw;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sw = selectionSort(A, N);
    printArray(A, N);
    cout << sw << endl;
    return 0;
}
