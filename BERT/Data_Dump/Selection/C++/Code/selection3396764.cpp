#include <iostream>
using namespace std;

int selectionSort(int A[], int N){
    int i, minj, j;
    int n = 0;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i],A[minj]);
        if(minj != i)n++;
    }
    return n;
}

void trace(int A[], int N){
    int i;
    for(i=0;i < N ;i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main(){
    int N, i;
    cin >> N;
    int A[100];
    for(i = 0; i < N; i++){
        cin >> A[i];
    }
    int n;
    n = selectionSort(A, N);
    trace(A, N);
    cout << n << endl;
    return 0;
}
