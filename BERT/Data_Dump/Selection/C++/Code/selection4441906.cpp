#include <iostream>
#include <stdio.h>
using namespace std;

int selectionSort(int A[], int N){
    int count = 0;
    for(int i = 0; i <= N - 1; i++){
        int minj = i;
        for(int j = i; j <= N - 1; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int ans = selectionSort(A, N);
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
    
    return 0;
}

