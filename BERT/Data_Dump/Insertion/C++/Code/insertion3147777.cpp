#include <iostream>
using namespace std;

void output(int A[], int N) {
    int i;

    for (i=0; i<N; i++){
        if (i>0) {
            cout << " ";
        }
        cout << A[i];
    }
    
    cout << endl;
}

void insertionSort(int A[], int N) {
    int i, j, v;
    
    for (i=0; i<N; i++) {
        v = A[i];
        j = i - 1;
        
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        output(A, N);
    }
}

int main() {
    int N, i;
    cin >> N;
    
    int A[N];
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    
    insertionSort(A, N);
    
    return 0;
}
