#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &v: A)
        cin >> v;
    
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                cnt++;
            }
        }
    }
    
    for(int i=0; i<N; i++)
        cout << A[i] << (i==N-1? "\n": " ");
    cout << cnt << endl;
    
    return 0;
}

