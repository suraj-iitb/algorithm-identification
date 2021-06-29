#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int Count = 0;
    
    for (int i = 0; i < N; i++) {
        int minKey = i;
        for (int j = i + 1; j < N; j++) {
            if (A[minKey] > A[j]) {
                minKey = j;
            }
        }
        if (minKey != i) {
            swap(A[i], A[minKey]);
            Count++;
        }
    }
    
    return Count;
}

int main(void) {
    int N, Count;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    Count = selectionSort(A, N);
    
    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    
    cout << endl;
    cout << Count << endl;
}
