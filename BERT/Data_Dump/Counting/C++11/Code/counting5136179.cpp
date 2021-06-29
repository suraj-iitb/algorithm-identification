#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void countingSort(const vector<int>& A, vector<int>& B, int k);

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> ret(n);
    countingSort(arr, ret, 10000);
    for (int i = 0; i < n; ++i){
        if(i > 0)
            cout << " ";
        cout << ret[i];
    }
    cout << endl;
    cin.get();
    cin.get();
    return 0;
}

void countingSort(const vector<int>& A, vector<int>& B, int k){
    int C[k + 1];
    memset(C, 0, sizeof(int) * (k + 1));
    int n = A.size();
    for (int i = 0; i < n; ++i){
        C[A[i]]++;
    }
    for (int i = 1; i <= k; ++i){
        C[i] = C[i - 1] + C[i];
    }
    for (int i = n - 1; i >= 0; --i){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}
