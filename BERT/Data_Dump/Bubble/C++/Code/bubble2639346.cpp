#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,ans=0;
    bool f=true;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    while(f){
        f=false;
        for(i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                swap(v[i],v[i+1]);
                ans++;
                f=true;
            }
        }
    }
    for(i=0;i<v.size();i++){
        cout<<v[i]<<((i<v.size()-1)?' ':'\n');
    }
    cout<<ans<<'\n';
    return 0;
}
