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

#define N_MAX 100000

struct Card{
    char suit;
    int value;
};

struct Card L[N_MAX/2],R[N_MAX/2];

void merge(struct Card A[],int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    REP(i,n1) L[i] = A[left+i];
    REP(i,n2) R[i] = A[mid+i];
    L[n1].value = INF;
    R[n2].value = INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i].value<=R[j].value){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(struct Card A[],int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int partition(struct Card A[],int p,int r){
    int i,j;
    struct Card t,x;
    x = A[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(A[j].value<=x.value){
            i++;
            t = A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i+1;
}

void quickSort(struct Card A[],int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    Card A[N_MAX],B[N_MAX];
    REP(i,n){
        cin>>A[i].suit>>A[i].value;
        B[i].suit=A[i].suit;
        B[i].value=A[i].value;
    }
    mergeSort(A,0,n);
    quickSort(B,0,n-1);
    bool stable=true;
    REP(i,n){
        if(A[i].suit!=B[i].suit) stable=false;
    }
    if(stable) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    REP(i,n) cout<<B[i].suit<<" "<<B[i].value<<endl;
}
