#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int INF = 1001001001;
int comp = 0;

void mergex(vector<int> &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1), R(n2+1);
    rep(i, n1){
        L[i] = A[left+i];
    }
    rep(i, n2){
        R[i] = A[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;

    int i = 0;
    int j = 0;

    for(int k = left; k < right; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
            comp++;
        } else {
            A[k] = R[j];
            j += 1;
            comp++;
        }
    }
    return;
}

void mergexSort(vector<int> &A, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergexSort(A, left, mid);
        mergexSort(A, mid, right);
        mergex(A, left, mid, right);
    }
    return;
}

int main() {
    int n; cin >> n;
    vector<int> S(n);
    rep(i, n){
        cin >> S[i];
    }

    mergexSort(S, 0, n);
    rep(i, n){
        cout << S[i];
        if(i == n-1){
            cout << endl;
        } else {
            cout << " ";
        }
    }

    cout << comp << endl;
}
