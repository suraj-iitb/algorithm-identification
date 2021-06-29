#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;
int cnt;
void merge(vector<int> &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    int i = 0, j = 0;
    L[n1] = INF;
    R[n2] = INF;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergesort(vector<int> &A, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    mergesort(S, 0, N);
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << S[i] << ' ';
        else cout << S[i] << endl;
    }
    cout << cnt << endl;
}
