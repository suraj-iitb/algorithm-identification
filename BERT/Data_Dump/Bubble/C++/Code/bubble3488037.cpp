#include <iostream>
using namespace std;

int bubbleSort( int A[], int N) {
    int i = 0, j;
    int count = 0;
    bool flag = 1;
    while ( flag) {
        flag = 0;
        for ( j = N - 1; j >= i+1; j--) {
            if ( A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                count++;
            }
        
        }
        i++;
    }
    return count;
}

int main() {
    int i, N;
    int A[100];
    int count;
    cin >> N;
    for ( i = 0; i < N; i++) cin >> A[i];
    
    count =  bubbleSort(A, N);
    
    for ( i = 0; i < N; i++) {
        if ( i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    

    return 0;

}
