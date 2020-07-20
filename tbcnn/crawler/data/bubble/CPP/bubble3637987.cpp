#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[100];
    for(int i = 0;i < N;++i) cin >> A[i];
    int flag = 1, count = 0;
    while(flag){
        flag = 0;
        for(int i = N - 1;i > 0;--i){
            if(A[i] < A [i-1]){
                int k = A[i];
                A[i] = A[i-1];
                A[i-1] = k;
                ++count;
                flag = 1;
            }
        }
    }
    cout << A[0];
    for(int i = 1;i < N;++i) cout << ' ' << A[i];
    cout << endl; 
    cout << count << endl;
}
