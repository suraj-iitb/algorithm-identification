#include <iostream>
#include <vector>
using namespace std;
int bubblesort(int N, vector<int> &A){
    int flag = 1;
    int cnt = 0;
    while(flag){
        flag = 0;
        for(int i = 0; i < N - 1; i++){
            if(A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int cnt = bubblesort(N, A);
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << A[i] << ' ';
        else cout << A[i] << endl;
    }
    cout << cnt << endl;
}
