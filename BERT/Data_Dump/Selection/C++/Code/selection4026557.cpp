#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int selection(vector<int> &a,int n);

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a.at(i);
    }
    int x=selection(a,n);
    rep(i,n){
        cout<<a.at(i);
        if(i!=n-1){
            cout<<' ';
        }
        else{
            cout<<endl;
        }
    }
    cout<<x<<endl;
    return 0;
}

int selection(vector<int> &a,int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a.at(j)<a.at(min)){
                min=j;
            }
        }
        if(min!=i){
            swap(a.at(min),a.at(i));
            c++;
        }
    }
    return c;
}
 
