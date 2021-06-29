#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n,ans=0;
    cin >> n;
    int x[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    
    
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(x[j]<x[minj])
                minj =j;
        }
        if(i!=minj){
            swap(x[i],x[minj]);
            ans++;
        }
    }
    
    
    for (int i=0; i<n; i++) {
        if(i==0)cout<< x[i];
        else cout <<" "<< x[i];
    }
    cout << endl << ans << endl;
    
}


