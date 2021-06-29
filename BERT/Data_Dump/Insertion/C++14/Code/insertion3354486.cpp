#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;

void trace(vector<int> A, int N){
    for(int i = 0; i < N; i++ ){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(vector<int> A, int N){
    int v, j;

    for (int i = 1; i < N; i++){
        v = A[i];
        j = i -1;

        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        
        }
        A[j + 1] = v;
        trace(A, N);

    }
}

int main(void){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    trace(A, N);
    insertionSort(A, N);

    
}
