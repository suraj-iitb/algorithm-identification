#include <iostream>
using namespace std;
void InsertionSort(int A[], int N){
    for(int i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for(int k = 0; k < N; k++){
            if(k == N - 1){
                cout << A[k] << endl;
            } else {
                cout << A[k] << " ";
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i == N - 1){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    InsertionSort(A, N);

    return 0;
}

