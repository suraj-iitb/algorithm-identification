#include <iostream>
using namespace std;
int main(void){
    int N, A[101];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int i = 0, minj, tmp, c = 0;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(A[minj] == A[i]) continue;
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp; 
        c++;
    }
    for(int k = 0; k < N; k++){
        cout << A[k];
        if(k == N - 1) cout << endl;
        else cout << " ";
    }
    cout << c << endl;
}

