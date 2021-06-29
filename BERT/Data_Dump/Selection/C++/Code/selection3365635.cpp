#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
    int i, j, sw=0, minj;
    for (i = 0; i < N - 1; i++){
        minj = i;
        for ( j = i; j < N; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[minj],A[i]);
        if (minj != i) sw++;
    }
    return sw;
}

int main(){
    int A[100], N, i, sw;
    
    cin >> N;
    for (i = 0; i < N; i++) cin >> A[i];
    sw = selectionSort(A, N);
    for (i=0; i<N; i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << "\n";
    cout << sw << endl;
    
    return 0;
}
