#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){
    int sw = 0;
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j >= i + 1; j--){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int sw = bubbleSort(A, N);

    for(int i = 0; i < N - 1; i ++){
        cout << A[i] << ' ';
    }

    cout << A[N - 1] << endl;
    cout << sw << endl;

    return 0;
}
