#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }
    for(int i=0; i<N; ++i){
        int v = A[i];
        int j = i-1;
        for(; v<=A[j] && j>=0; --j){
            A[j+1] = A[j];
        }
        A[j+1] = v;
        for(int k=0; k<N-1; ++k){
            cout << A[k] << " ";
        }
        cout << A[N-1] << "\n";
    }
    return 0;
}
