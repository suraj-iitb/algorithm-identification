#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int v=a[i];
        if(i!=0){
            for(int j=i-1;0<=j;j--){
                if(a[j]>v) {
                    a[j+1]=a[j];
                    a[j]=v;
                }
                else{
                    a[j+1]=v;
                    break;
            } 
            
        }
        }
        for(int i=0;i<n;i++){
            if(i==0){
                cout<<a[i];
            }
            else cout<<" "<<a[i];
        }
        cout<<endl;
        
    }
}
