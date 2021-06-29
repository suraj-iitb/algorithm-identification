#include <iostream>
using namespace std;

int main(){
    int N, count = 0, minj, s;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            s = A[i];
            A[i] = A[minj];
            A[minj] = s;
            count++;
        }
    }
    for(int i = 0; i < N; i++){
        if(i == N - 1){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }

    cout << count << endl;
    return 0;
}
