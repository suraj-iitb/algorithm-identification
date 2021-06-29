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
typedef long long lint;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define INF 1000000001;

struct Card{
    char suit;
    int value;
};

void merge(Card A[], int left, int mid ,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1+1], R[n2+1];

    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1].value=INF;
    R[n2].value=INF;
    int i=0;
    int j=0;

    for(int k=left; k<right;k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card A[],int left, int right){
    if(left + 1< right){
        int mid = (left + right)/2;
        mergeSort(A,left, mid);
        mergeSort(A,mid, right);
        merge(A,left,mid, right);
    }
}

int partition(Card A[],int p, int r){
    Card x = A[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(A[j].value <= x.value){
            i++;
            swap(A[i],A[j]); 
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(Card A[],int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void solve() {
    int n, v;
    char S[10];
    int stable = 1;
    cin >> n;
    Card A[n], B[n];
    rep(i,n) {
        cin >> S >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }
    
    quicksort(A,0,n-1);
    mergeSort(B,0,n);

    rep(i,n){
        if(A[i].suit != B[i].suit){
            stable = 0;
            break;
        }
    }

    if(stable==1) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    rep(i,n) cout << A[i].suit << " " << A[i].value << endl;

    // cout << ans << endl;
}
signed main() {

    solve();

    return 0;
}
