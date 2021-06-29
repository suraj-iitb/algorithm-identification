#include <iostream>
using namespace std;

int selectionSort(int A[], int N){
    int minj, count=0;
    for(int i=0; i <= N-1; i++){
        minj= i;
        for(int j=i; j <= N-1; j++){
            if (A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if (i != minj) count++;
    }
    return count;
}

int main(){
    int N, count;
    cin >> N;
    int A[100];
    for(int i=0; i<N; i++) cin >> A[i];
    count = selectionSort(A, N);
    for(int i=0; i<N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << count << endl;
    return 0;
}
