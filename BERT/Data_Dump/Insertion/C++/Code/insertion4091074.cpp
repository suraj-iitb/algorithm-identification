#include <iostream>
using namespace std;
void printArray(const int *A, int N){
    for(int i=0; i<N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
}

void insertionSort(int *A, int N){
    int v;
    for(int i=1; i<N; i++){
        v = A[i];
        int j = i-1;
        while( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
    }
}

int main(){
    int x;
    cin >> x;
    int* A = new int[x];
    for(int i=0; i<x; i++){
        cin >> A[i];
    }
    printArray(A, x);
    insertionSort(A, x);
    delete A;
}
