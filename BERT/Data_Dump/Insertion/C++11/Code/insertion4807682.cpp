#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n - 1; i++) cout << A[i] << " ";
    cout << A[n - 1] << '\n';
    for(int i = 1; i < n; i++){
        int key = A[i];
        /* insert A[i] into the sorted sequence A[0,...,j-1] */
        int j = i - 1;
        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = key;
        for(int i = 0; i < n - 1; i++) cout << A[i] << " ";
        cout << A[n - 1] <<  "\n";
    }
}
