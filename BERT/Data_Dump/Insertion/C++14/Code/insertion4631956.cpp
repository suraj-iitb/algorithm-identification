#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define FOR(b) for(auto&e:b)
#define INSERT(x) inserter(x,x.end())
int main(){
    #ifdef mark
    freopen("in.txt","r",stdin);
    #endif // mark
    int n;
    cin>>n;
    vector<int> v;
    back_insert_iterator<vector<int> > back_it(v);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        back_it=k;
    }
    for(int k=0;k<v.size();k++){
        if(k)cout<<' ';
        cout<<v[k];
    }
    cout<<endl;
    for(int i=1;i<v.size();i++){
        int key=v[i],j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
        for(int k=0;k<v.size();k++){
            if(k)cout<<' ';
            cout<<v[k];
        }
        cout<<endl;
    }
}

