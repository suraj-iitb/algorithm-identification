#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

void trace(vector<int> A){
    rep(i,A.size()){
        cout << A[i];
        if (i != A.size()-1) cout << " ";
    }
    cout << endl;
}

void insertion_sort(vector<int> A, int N){
    for(int i = 1; i < N; ++i){
        int j = i - 1;
        int tmp = A[i];
        while(j >= 0 && A[j] > tmp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
        trace(A);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    trace(A);
    insertion_sort(A, N);
}
