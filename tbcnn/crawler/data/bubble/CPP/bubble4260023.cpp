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
    bool flag=true;
    
    while(flag){
        flag=false;
        
        for(int i=n-1;i>0;i--){
            if(hoge.at(i)<hoge.at(i-1)){
                int pre=hoge.at(i);
                hoge.at(i)=hoge.at(i-1);
                hoge.at(i-1)=pre;
                
                flag=true;
                cnt++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<hoge.at(i);
        if(i!=n-1) cout<<" ";
    }
    
    cout<<endl<<cnt<<endl;
    
    return 0;
}
