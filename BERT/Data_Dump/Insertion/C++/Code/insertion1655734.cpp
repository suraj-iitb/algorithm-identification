#include <iostream>
#include <algorithm>
using namespace std;

void trace(int A[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << "" << endl;
}

void insertionSort(int A[], int N){

    for(int i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;

        while(j >= 0 && v < A[j]){
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = v;
        trace(A, N);
    }
}

int main(void){
    
    int A[100], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    trace(A, n);
    insertionSort(A, n);

    return 0;
    
}
