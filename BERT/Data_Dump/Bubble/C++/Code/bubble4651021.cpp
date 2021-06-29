#include <iostream>
using namespace std;

int main(){
    int N, count = 0, s;
    bool flag = true;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    while(flag == true){
        flag = false;
        for(int j = N - 1; j > 0; j--){
            if(A[j] < A[j - 1]){
                s = A[j];
                A[j] = A[j - 1];
                A[j - 1] = s;
                flag = true;
                count++;
            }
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
