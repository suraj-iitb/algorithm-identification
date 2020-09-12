#include<iostream>
using namespace std;

void printSort(int A[], int N){
    cout << A[0];
    for(int i=1; i<N; i++){
        cout << " " << A[i];
    }
    cout << "" << endl;
}

void insertionSort(int A[], int N){
    int v, i, j;
    for(i=1; i<N; i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        A[j+1] = v;
        }
        printSort(A, N);
    }
}

int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    printSort(A, N);
    insertionSort(A,N);
    return 0;
}
