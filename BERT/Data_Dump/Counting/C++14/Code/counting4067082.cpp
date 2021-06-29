#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int c[100001];
int main(){
    int n;cin >> n;
    a.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(auto &i:a) c[i]++;
    for(int i=1;i<100001;i++){
        c[i] = c[i]+c[i-1];
    }
    b.resize(n);
    
    for(int j=n-1;j>=0;j--){
        
        b[c[a[j]]-1] = a[j];
        c[a[j]]--;
    }
    for(int i=0;i<b.size();i++){
        cout << b[i];
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
}


