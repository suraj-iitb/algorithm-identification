#include <iostream>
using namespace std;

void printArray(int A[], int N){
    
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i<N-1) cout << " ";
    }
    
    cout << endl;
    
}

void insertionSort(int A[], int N){
    
    printArray(A, N);
    
    for(int i=1; i<N; i++){
        int v = A[i];
        int j = i - 1;
        while( j>=0 && A[j]>v ){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
        //if(i<N-1) cout << endl;
    }
    
}

int main() {
    
    int N;
    cin >> N;
    
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    insertionSort(A, N);
    
    return 0;
    
}

