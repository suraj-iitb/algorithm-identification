#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
    int t = 0;
    for(int i = 0; i <= N - 2; i++){
        int minj = i;
        for(int j = i; j <= N - 1; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) t++;
    }
    return t;
}

int main(){
    int A[100], N, t;
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    t = selectionSort(A, N);
    
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl << t << endl;
    
    return 0;
}
