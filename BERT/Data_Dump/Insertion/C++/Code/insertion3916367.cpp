#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
        
        for(int k=0; k<n; k++){
            if(k!=n-1)cout<<a[k]<<" ";
            else cout<<a[k]<<endl;
        }
      
    }
    



    
    return 0;
}

