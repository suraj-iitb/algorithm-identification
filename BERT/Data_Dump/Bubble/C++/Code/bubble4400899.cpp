#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    int cn=0;
    for(int i=n-1;i>0;i--){
        for(int j=n-1;j>n-i-1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                cn++;
                
            } 
        }
    }    
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cn<<endl;    
}
