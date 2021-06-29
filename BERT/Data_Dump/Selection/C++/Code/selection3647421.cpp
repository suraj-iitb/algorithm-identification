#include<iostream>
using namespace std;

int selectonSort(int A[], int N){
    int sw = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj){
            sw++;
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
    
    int sw = selectonSort(A, N);

    for(int i = 0; i < N - 1; i++){
        cout << A[i] << ' ';
    }
    cout << A[N - 1] << endl;
    cout << sw << endl;

    return 0;
}
