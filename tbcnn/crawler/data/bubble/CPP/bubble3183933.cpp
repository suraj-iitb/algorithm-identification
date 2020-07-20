#include<iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int swapCount = 0;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for ( int i = 0; i < N-1; i++ ) {
            if ( A[i] > A[i+1] ) {
                swap(A[i], A[i+1]);
                sorted = false;
                swapCount++;
            }
        }
        N--;
    }
    return swapCount;
}

int main() {
    int A[100], N, sw;
    cin >> N;
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    
    sw = bubbleSort(A, N);
    
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    
    return 0;
}
