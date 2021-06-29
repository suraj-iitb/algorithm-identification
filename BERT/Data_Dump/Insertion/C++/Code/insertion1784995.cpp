#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int *A, int N) {
    for (int i = 1; i <= N-1; i++) {
        int v = A[i];
        int j = i-1;
        
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        } 
        
        A[j+1] = v;
        
        for (int k = 0; k < N-1; k++) {
            cout << A[k] << " ";
        }
        
        cout << A[N-1] <<  endl;
    }
}

int main(int argc, char** argv) {
    int N = 0;
    int Array[1000] = {0};
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> Array[i];
    }
    
    for (int j = 0; j < N-1; j++) {
        cout << Array[j] <<" ";
    }
    
    cout << Array[N-1] << endl;
    
    insertionSort(Array, N);
    
    return 0;
}
