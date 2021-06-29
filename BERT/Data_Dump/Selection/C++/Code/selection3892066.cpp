#include <iostream>
using namespace std;


//選択ソート
int selectionSort(int A[], int N) {
    int minj, sw = 0, t;
    for ( int i = 0; i < N - 1; i++ ) {
        minj = i;
        for ( int j = i; j < N; j++ ) {
            if ( A[j] < A[minj] ) minj = j;
        } 
        t = A[i]; A[i] = A[minj]; A[minj] = t;
        if ( i != minj ) sw++;
    }
    return sw;
}

int main(){
    int A[100], N, sw;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sw = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i>0) cout << " " ;
        cout << A[i];
    }
    cout << "\n" << sw << endl;

    
    return 0;
}
