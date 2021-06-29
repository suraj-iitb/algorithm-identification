#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,min,ans=0;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        if(v[i]!=v[min]){
            swap(v[i],v[min]);
            ans++;
        }
    }
    for(i=0;i<v.size();i++){
        cout<<v[i]<<((i<v.size()-1)?' ':'\n');
    }
    cout<<ans<<'\n';
    return 0;
}
