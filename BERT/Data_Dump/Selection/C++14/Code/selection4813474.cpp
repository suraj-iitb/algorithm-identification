#include <iostream>
#include <vector>
using namespace std;
int selesort(int N, vector<int> &A){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int ind = i;
        for(int j = i + 1; j < N; j++){
            if(A[j] < A[ind]) ind = j;
        }
        if(i != ind){
            swap(A[i], A[ind]);
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int cnt = selesort(N, A);
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << A[i] << ' ';
        else cout << A[i] << endl;
    }
    cout << cnt << endl;
}
