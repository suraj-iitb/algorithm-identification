#include <iostream>
using namespace std;

void insertionSort(int A[], int N);
void trace(int A[], int N);

int main(){
    int i, N;
    cin >> N;
    int A[N];
    for(i = 0; i < N; i++){
        cin >> A[i];
    }
    insertionSort(A, N);
    return 0;
}

void trace(int A[], int N){
    int i;
    for(i=0;i < N ;i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N){
    trace(A, N);
    for(int i = 1; i < N; i++){
        int v, j;
        v = A[i];
        j = i - 1;
        while( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}
