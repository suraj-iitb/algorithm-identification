#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
// #ifdef DEBUG 
// #define

void Insertion_Sort(int A[], int n){
    for(int i=0; i<n; i++){
        int v= A[i];
        for(int j=i-1; j>=0; j--){
            if(v<A[j]){
                int tmp;
                tmp= A[j+1];
                A[j+1]= A[j];
                A[j]= tmp;
            }
        }
        REP(i,n) cout << A[i] << ((i!=n-1)?" ":"");
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    int A[n];
    REP(i,n) cin >> A[i];
    Insertion_Sort(A,n);
    return 0;
}

