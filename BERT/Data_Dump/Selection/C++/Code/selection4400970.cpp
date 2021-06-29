#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cn=0;
    for(int i=0;i<n;i++){
        int min=a[i];
        int num=i;
        for(int j=i;j<n;j++){
            if(min>a[j]){
                min=a[j];
                num=j;
            }
        }
        if(a[i]>min){
            swap(a[i],a[num]);
            cn++;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cn<<endl;
}
