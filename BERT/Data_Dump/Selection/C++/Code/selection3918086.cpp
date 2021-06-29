#include <bits/stdc++.h>
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
    
    int sum = 0;
    for(int i=0; i<n; i++){
        int m = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[m]){
                m =j;
            }
        }
        if(i!=m){
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
            sum++;
        }
        

    }
    
    for(int i=0; i<n; i++){
        if(i!=n-1)cout<<a[i]<<" ";
        else cout<<a[i]<<endl;
    }
    cout<<sum<<endl;
    
    return 0;
}
