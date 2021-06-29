#include<iostream>
using namespace std;


int selectionSort(int A[], int N){
    int cnt = 0;
    int minj;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(A[i] != A[minj]){
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int A[100], N, sw;
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    sw = selectionSort(A, N);

    for(int i=0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << sw << endl;

    return 0;
}

