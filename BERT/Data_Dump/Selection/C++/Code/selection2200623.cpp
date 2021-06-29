#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
        int i, j, t, sw = 0, mini;
        for(i = 0; i < N; i++) {
                mini = i;
                for(j = i; j < N; j++) {
                        if(A[j] < A[mini]) mini = j;
                }
                t = A[i]; A[i] = A[mini]; A[mini] = t;
                if(i != mini) sw++;
        }
        return sw;
}

int main() {
        int A[100], N, i, sw;
        cin >> N;
        for(i = 0; i < N; i++) cin >> A[i];
        sw = selectionSort(A, N);
        for(int j = 0; j < N; j++) {
                if(j > 0) cout << " ";
                cout << A[j];
        }
        cout << endl;
        cout << sw << endl;
        return 0;
}
