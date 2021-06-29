#include<iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int Count = 0;
    bool IsContinue = true;
    
    for (int i = 0; IsContinue; i++) {
        IsContinue = false;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                IsContinue = true;
                Count++;
            }
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
    
    Count = bubbleSort(A, N);
    
    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    
    cout << endl;
    cout << Count << endl;
    
    return 0;
}
