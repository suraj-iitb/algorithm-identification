#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MAX_M 100000
const int INF = 1e9;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i+1<n) cout<<" ";
    }
    cout<<endl;
}
