#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,s,c=0;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(v[j]<v[j-1]){
                s=v[j];
                v[j]=v[j-1];
                v[j-1]=s;
                c++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << ((i==n-1)?"":" ") ;
    }
    cout<<endl<<c<<endl;
}
