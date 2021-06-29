#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int bubblesort(vector<int> &a,int n);

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a.at(i);
    }
    int x=bubblesort(a,n);
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

int bubblesort(vector<int> &a,int n){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(a.at(j)<a.at(j-1)){
                int tmp=a.at(j);
                a.at(j)=a.at(j-1);
                a.at(j-1)=tmp;
                c++;
            }
            
        }
    }
    return c;
}
 
