#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> a(N),b(N),c(20000000,0);
    for(int i=0;i<N;i++){
        cin >> a[i];
        c[a[i]]++;
    }
    for(int i=1;i<c.size();i++){
        c[i]+=c[i-1];
    }
    for(int i=N-1;i>=0;i--){
        int x=c[a[i]];
        b[x-1]=a[i];
        c[a[i]]--;
    }
    for(int i=0;i<N;i++){
        cout<<b[i];
        if(i!=N-1)cout<<" ";
    }
    cout<<endl;
    return 0;
}
