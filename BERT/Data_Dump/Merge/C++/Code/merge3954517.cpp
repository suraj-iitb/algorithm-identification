//id:miiifa (AOJ,PEどちらも)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)
vector<ll> A;
int cnt= 0;
void merge(int left, int mid, int right){
    int n1= mid-left, n2= right-mid;
    ll l[n1+1],r[n2+1];

    for(int i=0; i<n1; i++) l[i]= A[left+i];
    for(int i=0; i<n2; i++) r[i]= A[mid+i];
    l[n1]= INF; r[n2]= INF;
    int cntl= 0,cntr= 0;
    for(int i=0; i<right-left; i++){
        cnt++;
        if(l[cntl]<r[cntr]){
            A[left+i]= l[cntl];
            cntl++;
        } else{
            A[left+i]= r[cntr];
            cntr++;
        }
    }
}
void divide(int left, int right){
    if(left+1<right){
        int mid= (left+right)/2;
        divide(left,mid);
        divide(mid,right);
        // cout << ((left==0)?"(":" ");
        // REP(i,A.size()) cout << A[i] << ((i==left-1)?"(":((i==mid-1)?"|":((i==right-1)?")":" ")));
        // cout << endl;   
        merge(left,mid,right);
    }
}

int main(){
    int n;
    cin >> n;
    A.resize(n);
    REP(i,n) cin >> A[i];
    divide(0,n);
    REP(i,n) cout << A[i] << ((i!=n-1)?" ":"");
    cout << endl;
    cout << cnt << endl;
}
