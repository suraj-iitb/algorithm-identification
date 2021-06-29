#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
#define REP3(i,x,n) for(ll i=x; i>(n); i--)
#define ALL(n) begin(n),end(n)
#define MAX 500000
#define SENTINEL 2000000000
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

ll L[MAX/2+2],R[MAX/2+2];
ll cnt;
void merge(ll A[],ll n,ll left,ll mid ,ll right){
    ll n1 = mid   - left;
    ll n2 = right - mid;
    REP(i,n1)L[i] = A[left+i];
    REP(i,n2)R[i] = A[mid+i];
    L[n1] = R[n2] = SENTINEL;
    ll i = 0,j = 0;
    REP2(k,left,right){
        cnt++;
        if(L[i]<=R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}
void mergeSort(ll A[],ll n,ll left,ll right){
    if(left+1<right){
        ll mid = (left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    ll A[MAX],n;
    cnt = 0;
    cin >> n;
    REP(i,n){cin>>A[i];}
    mergeSort(A,n,0,n);
    REP(i,n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
