#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll int64_t
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int L[252525],R[252525];
int cnt=0;
int n;

void merge(int A[],int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    REP(i,n1) L[i] = A[left+i];
    REP(i,n2) R[i] = A[mid+i];
    L[n1] = INF;
    R[n2] = INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(int A[],int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int A[505050];
    REP(i,n) cin>>A[i];
    mergeSort(A,0,n);

    REP(i,n){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
}
