#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N){
    int i, j, minj;
    int sw = 0;
    for(i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    return sw;
}
int main(){
    int A[100], N, i, sw;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sw = selectionSort(A, N);
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
}
