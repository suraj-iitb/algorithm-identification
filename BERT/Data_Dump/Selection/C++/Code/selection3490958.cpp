#include <iostream>
using namespace std;


int selectionSort ( int A[], int N) {
    int i, j;
    int minj;
    int count = 0;
    for ( i = 0; i < N; i++) {
        minj = i;
        for ( j = i; j < N; j++) {
            if ( A[j] < A[minj])
                minj = j;
        }
        swap(A[i], A[minj]);
        if ( i != minj)
            count++;

    }

    return count;
}


int main () {
    int i, N;
    int A[100];
    int count;

    cin >> N;
    for ( i = 0; i < N; i++) cin >> A[i];

    count = selectionSort(A, N);
    for ( i = 0; i < N; i++) {
        if ( i > 0) 
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
   
    return 0;
}
        


