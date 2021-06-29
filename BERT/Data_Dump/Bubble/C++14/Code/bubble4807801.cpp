#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const ll INF = 1001001001;
const ll mod = 1000000007;

vector<int> A;
int cnt = 0;

void BubbleSort(int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= i + 1; --j){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                cnt++;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    BubbleSort(n);
    for(int i = 0; i < n - 1; i++) cout << A[i] << " ";
    cout << A[n - 1] << '\n';
    cout << cnt << endl;
}
