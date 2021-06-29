#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bubble_Sort(int A[], int N){
    int res = 0;
    for(int i = 0; i < N -1; ++i){
        for(int j = N-1; j > i; --j){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                ++res;
            }
        }
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    int A[110];
    for(int i = 0; i < N; ++i) cin >> A[i];
    int res = bubble_Sort(A, N);
    for(int i = 0; i < N-1; ++i) cout << A[i] << " ";
    cout << A[N-1] << endl;
    cout << res << endl;
    return 0;

}
