#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> hoge(n);
    for(int i=0;i<n;i++) cin>>hoge.at(i);
    
    for(int i=0;i<n;i++){
        cout<<hoge.at(i);
        if(i<n-1) cout<<" ";
    }
    cout<<endl;
    
    for(int i=1;i<n;i++){
        int a=hoge.at(i);
        int j=i-1;
        
        while(0<=j && hoge.at(j)>a){
            hoge.at(j+1)=hoge.at(j);
            j--;
        }
        
        hoge.at(j+1)=a;
        
        for(int i=0;i<n;i++){
            cout<<hoge.at(i);
            if(i<n-1) cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
