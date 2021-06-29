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
    for(int z=0; z<n; z++){
        for(int i=n-1; i>0; i--){
            int temp = a[i];
            if(a[i-1]>a[i]){
                a[i]=a[i-1];
                a[i-1]= temp;
                sum++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(i!=n-1)cout<<a[i]<<" ";
        else cout<<a[i]<<endl;
    }
    cout<<sum<<endl;
    
    return 0;
}
