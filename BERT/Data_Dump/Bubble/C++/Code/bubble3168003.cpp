#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for ( int i = 0; i < N; i++) cin >> A[i];
    bool flag = true;
    int mem;
    int cnt = 0;
    
    while (flag == true) {
        flag = false;
        for ( int j = N - 1; j > 0; j--){
            if ( A[j] < A[j-1]){
                mem = A[j];
                A[j] = A[j-1];
                A[j-1] = mem;
                cnt++;
                flag = true;
            }
        }
    }
    
    for (int i = 0; i < N; i++){
        cout << A[i];
        if (i < N - 1) cout << " ";
        else cout << endl;
    }
    cout << cnt << endl;
}
