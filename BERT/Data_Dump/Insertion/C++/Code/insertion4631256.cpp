#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>s(1,0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s.push_back(t);
    }
    for(int i=1;i<=n;i++){
        int v=s[i];
        int j=i-1;
        while(j>0&&s[j]>v){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=v;
        for(int i=1;i<=n;i++){
            cout<<(i==1?"":" ")<<s[i];
        }
        cout<<endl;
    }
}
