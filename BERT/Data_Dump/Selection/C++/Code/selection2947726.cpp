#include<iostream>

using namespace std;

int selectionSort(int A[], int N){
    int sw = 0;
    
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }

        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }

    return sw;
}

int main(){
    int A[100], N, sw;

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sw = selectionSort(A, N);

    for(int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
