#include <iostream>
#include <algorithm>
#define SIZE 100
using namespace std;

void showlist(int A[], const int N){
    for (int i = 0; i < N - 1; i++){
        cout << A[i] << ' ' ;
    }
    cout << A[N-1] << endl;
}

int* insertionSort(int A[], const int N){
    for (int i = 0; i < N; i++){
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        showlist(A, N);
    }
    return A;
}

int main(int argc, char const *argv[]) {
    //標準入力を配列に入れる
    int N;
    cin >> N;
    int A[SIZE];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    insertionSort(A, N);
    return 0;
}

