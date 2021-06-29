#include <iostream>
using namespace std;
int main(){
    int N, tmp;
    int A[101];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int j = 2; j <= N; j++){
        for(int i = 0; i < N; i++){
            cout << A[i];
            if(i == N - 1) cout << endl;
            else cout << " ";
        }
        tmp = A[j - 1];
        int k = (j - 1) - 1;
        while(k >= 0 && A[k] > tmp){
            A[k + 1] = A[k];
            k--;
        }
        A[k + 1] = tmp;
    }

    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i == N - 1) cout << endl;
        else cout << " "; 
    }
}

