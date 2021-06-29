#include<iostream>
using namespace std;

int SelectionSort(int A[], int N){
    int sw = 0;
    int j = 0;
    int minj = 0;
    for(int i = 0; i < N - 1; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(i != minj) {
            sw++;
            swap(A[i], A[minj]);
        }
    }
    return sw;
}

int main(){
    int A[100], N;

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    int sw = SelectionSort(A, N);

    for(int i  = 0; i < N; i++){
        if(i) cout << " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;

    return 0;
}
