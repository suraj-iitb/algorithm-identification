#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
    int i, j, t, sw=0, minj;
    for(int i=0; i<N-1; i++) {
        minj=i;
        for(int j=i; j<N; j++) {
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
    for(int i=0; i<N; i++) cin >> A[i];
    sw = selectionSort(A, N);

    for(int i=0; i<N; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
