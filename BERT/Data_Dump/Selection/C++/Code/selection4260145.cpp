#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> hoge(n);
    for(int i=0;i<n;i++) cin>>hoge.at(i);
    int cnt=0;
    
    for(int i=0;i<n;i++){
        int minj=i;
        
        for(int j=i;j<n;j++){
            if(hoge.at(minj)>hoge.at(j)){
                minj=j;
            }
        }
        
        if(minj!=i){
            int pre=hoge.at(i);
            hoge.at(i)=hoge.at(minj);
            hoge.at(minj)=pre;
            
            cnt++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<hoge.at(i);
        if(i<n-1) cout<<" ";
    }
    
    cout<<endl<<cnt<<endl;
    
    return 0;
}