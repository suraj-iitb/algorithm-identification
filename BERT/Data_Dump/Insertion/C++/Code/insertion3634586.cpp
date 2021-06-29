#include<iostream>
using namespace std;
void trace(int A[], int N){
    int i;
    for(i =0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionsort(int A[], int N){
    int i, j, v;
    for( i= 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while( j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(){
    int N, i, j;
    int A[100];
    
    cin >> N;
    for(i = 0; i < N; i++) cin >> A[i];
    
    trace(A, N);
    insertionsort(A, N);
    
    return 0;
}
