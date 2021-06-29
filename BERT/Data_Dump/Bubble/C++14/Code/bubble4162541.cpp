#include <iostream>
using namespace std;
int main(void){
    int N, c = 0, tmp;
    int A[101];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            if(A[j] > A[j + 1]){
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                c++;
            }  
        }
    }
    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i == N - 1) cout << endl;
        else cout << " "; 
    }
    cout << c << endl;
}

