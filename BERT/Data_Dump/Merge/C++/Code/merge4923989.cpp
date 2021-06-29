# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define INF 1000000001;

int cnt = 0;

void merge(int A[], int left, int mid ,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];

    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1]=INF;
    R[n2]=INF;
    int i=0;
    int j=0;

    for(int k=left; k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void mergeSort(int A[],int left, int right){
    if(left + 1< right){
        int mid = (left + right)/2;
        mergeSort(A,left, mid);
        mergeSort(A,mid, right);
        merge(A,left,mid, right);
    }
}

void solve() {
    int N;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];

    mergeSort(A,0,N);
    rep(i,N){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;
    
}
signed main() {

    solve();

    return 0;
}
