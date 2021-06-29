#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N){
    for (int i = 0; i < N; i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int selectionSort(vector<int> A, int N){
    int sw = 0;
    for (int i = 0; i < N; i++){
        int minj = i;
        bool flag = false;
        for (int j = i; j < N; j++){
            if (A[j] < A[minj]){
                minj = j;
                flag = true;
            }
        }
        if (flag) sw++; 
        swap(A[i], A[minj]);
    }

    trace(A, N);
    cout << sw << endl;
}

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    selectionSort(A, N);
}
